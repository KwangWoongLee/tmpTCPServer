#include "pch.h"
#include "Room.h"
#include "Player.h"
#include "GameSession.h"
#include "ClientPacketHandler.h"

Room::Room(uint8 roomId, GameMap&& gameMap)
	: mId(roomId),
	mGameMap(gameMap)
{
}

void Room::Init()
{
	mGameMap.Init(GetRoomRef());

}

void Room::Enter(ActorRef actor, bool playerEnter)
{
	actor->Spawn(GetRoomRef());

	if (playerEnter)
	{
		auto playerRef = static_pointer_cast<Player>(actor);
		{

			//원래 있던 객체 보내주기
			Protocol::S_SPAWN spawnPkt;

			{
				auto spawnActor = spawnPkt.add_actor();
				spawnActor->set_id(0);
				spawnActor->set_name(u8"배경");
				spawnActor->set_type(Protocol::ActorType::ACTOR_TYPE_BG);
				actor->SetDetailType(spawnActor);

				auto pos = spawnActor->mutable_position();
				int gameScale = 2;
				pos->set_x(mGameMap.mMapRange[1] * 32 * gameScale / 2);
				pos->set_y((mGameMap.mMapRange[3] -1) * 32 * gameScale / 2 );

			}

			for (auto [id, actor] : mActorMap)
			{
				auto spawnActor = spawnPkt.add_actor();
				spawnActor->set_id(actor->mId);
				spawnActor->set_name(actor->mName);
				spawnActor->set_type(actor->mType);
				actor->SetDetailType(spawnActor);

				auto pos = spawnActor->mutable_position();
				pos->set_x(actor->mPos.first);
				pos->set_y(actor->mPos.second);

			}

			auto spawnPacketBuffer = ClientPacketHandler::MakeSendBuffer(spawnPkt);

			playerRef->mOwnerSession->Send(spawnPacketBuffer);
		}

		mPlayerMap[actor->mId] = playerRef;
		Protocol::S_ENTER_GAME enterGamePkt;
		enterGamePkt.set_success(true);
		enterGamePkt.set_playerid(actor->mId);

		auto enterPacketBuffer = ClientPacketHandler::MakeSendBuffer(enterGamePkt);

		playerRef->mOwnerSession->Send(enterPacketBuffer);
	}



	{
		Protocol::S_SPAWN spawnPkt;

		auto spawnActor = spawnPkt.add_actor();
		spawnActor->set_id(actor->mId);
		spawnActor->set_name(actor->mName);
		spawnActor->set_type(actor->mType);
		actor->SetDetailType(spawnActor);
	
		auto pos = spawnActor->mutable_position();
		pos->set_x(actor->mPos.first);
		pos->set_y(actor->mPos.second);

		auto spawnPacketBuffer = ClientPacketHandler::MakeSendBuffer(spawnPkt);

		Broadcast(spawnPacketBuffer);
	}

	mActorMap[actor->mId] = actor;
}

void Room::Leave(ActorRef actor)
{
	std::cout << actor->mId << "가 룸에서 떠남" << std::endl;
	mPlayerMap.erase(actor->mId);
	mActorMap.erase(actor->mId);

	Protocol::S_DESPAWN broadCastPkt;

	auto despawnnActor = broadCastPkt.add_actor();
	despawnnActor->set_id(actor->mId);

	auto broadCastBuffer = ClientPacketHandler::MakeSendBuffer(broadCastPkt);
	Broadcast(broadCastBuffer);
}

void Room::Broadcast(SendBufferRef sendBuffer)
{
	for (auto [id, playerRef] : mPlayerMap)
	{
		playerRef->mOwnerSession->Send(sendBuffer);
	}
}

void Room::Update()
{

}

void Room::ApplyMove(Protocol::C_ACTION pkt)
{
	auto actor = pkt.actor();
	auto type = actor.type();
	auto id = actor.id();
	auto pos = actor.position();

	if (auto actorRef = findActor(id))
	{
		if (mGameMap.ApplyMove(actorRef, { pos.x(), pos.y()}) == false)
			return;

		std::cout << actorRef->mId << "가 (" << pos.x() << ", " << pos.y() << ")로 이동" << std::endl;

		{
			Protocol::S_ACTION  broadCastPkt;
			broadCastPkt.set_playeraction(pkt.playeraction());

			auto actionActor = broadCastPkt.mutable_actor();
			actionActor->set_id(id);
			actionActor->set_type(type);
			auto destPos = actionActor->mutable_position();
			destPos->set_x(pos.x());
			destPos->set_y(pos.y());

			auto broadCastBuffer = ClientPacketHandler::MakeSendBuffer(broadCastPkt);
			Broadcast(broadCastBuffer);
		}
	}
}


void Room::ApplyPlayerBomb(PlayerRef bombOwner)
{
	if (bombOwner == nullptr)
		return;

	

	ActorRef actor = MakeShared<Bomb>(bombOwner->mOwnerSession);
	actor->mName = u8"폭탄";
	actor->mType = Protocol::ActorType::ACTOR_TYPE_BOMB;
	auto startPos = bombOwner->SearchBombPosition();
	actor->SetStartPosition(startPos, false);

	actor->Spawn(GetRoomRef());

	mActorMap[actor->mId] = actor;

	std::cout << "플레이어 (" << bombOwner->mId << ")가 (" << actor->mId << ")로 공격" << std::endl;

	{
		Protocol::S_SPAWN spawnPkt;

		auto spawnActor = spawnPkt.add_actor();
		spawnActor->set_id(actor->mId);
		spawnActor->set_name(actor->mName);
		spawnActor->set_type(actor->mType);
		actor->SetDetailType(spawnActor);

		auto pos = spawnActor->mutable_position();
		pos->set_x(actor->mPos.first);
		pos->set_y(actor->mPos.second);

		auto spawnPacketBuffer = ClientPacketHandler::MakeSendBuffer(spawnPkt);

		Broadcast(spawnPacketBuffer);

		DoTimer(3000, [id = actor->mId, room = actor->mRoom]() {
				if (auto roomRef = room.lock())
				{
					auto actor = roomRef->findActor(id);
					if (actor)
					{
						Protocol::S_DESPAWN broadCastPkt;

						auto despawnnActor = broadCastPkt.add_actor();
						despawnnActor->set_id(actor->mId);

						auto broadCastBuffer = ClientPacketHandler::MakeSendBuffer(broadCastPkt);
						roomRef->Broadcast(broadCastBuffer);
					}
				}
			});
	}
}


void Room::ApplyExplodeBomb(uint64 bombId)
{
	auto actor = findActor(bombId);
	auto bomb = dynamic_pointer_cast<Bomb>(actor);

	if (bomb)
	{
		auto [x, y] = bomb->mPos;

		Vector<ActorRef> toLeaves;
		for (auto [id, mapActor] : mActorMap)
		{
			if (id != bomb->mId && bomb->IsInRange(mapActor))
			{
				toLeaves.push_back(mapActor);
			}
		}

		for (auto leaveActor : toLeaves)
			Leave(leaveActor);

		toLeaves.clear();
	}

	mActorMap.erase(bombId);
}


bool Room::IsCollision(ActorRef actor, Position dest)
{
	auto myId = actor->mId;
	for (auto [id, mapActor] : mActorMap)
	{
		if (id == myId) continue;
		if (mapActor->mType == Protocol::ACTOR_TYPE_PLAYER) continue;
		if (mapActor->mType == Protocol::ACTOR_TYPE_BOMB) continue;

		auto [x,y] = mapActor->mPos;
		auto [destX, destY] = dest;
		//나중에 Position 구조체안에 오버로딩

		float fDistanceX = fabsf(x - destX);
		float fRadCX = (mapActor->mWidthSize + actor->mWidthSize) / 2;

		float fDistanceY = fabsf(y - destY);
		float fRadCY = (mapActor->mHeightSize + actor->mHeightSize) / 2;

		if (fDistanceX < fRadCX && fDistanceY < fRadCY)
			return true;
	}

	return false;
}


ActorRef Room::findActor(uint64 id)
{
	if (mActorMap.find(id) == mActorMap.end())
		return nullptr;
	return mActorMap[id];
}