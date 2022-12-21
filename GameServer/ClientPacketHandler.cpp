#include "pch.h"
#include "ClientPacketHandler.h"
#include "Player.h"
#include "Room.h"
#include "GameSession.h"
#include "RoomManager.h"

PacketHandlerFunc GPacketHandler[UINT16_MAX];

// 직접 컨텐츠 작업자

bool Handle_INVALID(PacketSessionRef& session, BYTE* buffer, int32 len)
{
	PacketHeader* header = reinterpret_cast<PacketHeader*>(buffer);
	// TODO : Log
	return false;
}

bool Handle_C_ENTER_GAME(PacketSessionRef& session, Protocol::C_ENTER_GAME& pkt)
{
	GameSessionRef gameSession = static_pointer_cast<GameSession>(session);

	// TODO : Validation
	// 레디스에서 가져온 정보로 할것
	//string roomKey = pkt.roomkey();
	string name = u8"웅이";
	uint64 aidx = 1;
	uint8 roomId = 1;


	gameSession->mMyPlayer = MakeShared<Player>(gameSession);
	ActorRef actorRef = gameSession->mMyPlayer;
	actorRef->mName = name;
	actorRef->mType = Protocol::ActorType::ACTOR_TYPE_PLAYER;
	
	actorRef->SetStartPosition({0,0}, true);

	GRoomManager->DoAsync(&RoomManager::HandleEnterGame, roomId, actorRef);

	return true;
}

bool Handle_C_LEAVE_GAME(PacketSessionRef& session, Protocol::C_LEAVE_GAME& pkt)
{
	GameSessionRef gameSession = static_pointer_cast<GameSession>(session);

	auto player = gameSession->mMyPlayer;
	if (auto room = player->mRoom.lock())
	{
		room->DoAsync(&Room::Leave, static_pointer_cast<Actor>(player));
	}

	player = nullptr;

	return true;
}

bool Handle_C_BROADCAST_ROOM(PacketSessionRef& session, Protocol::C_BROADCAST_ROOM& pkt)
{
	GameSessionRef gameSession = static_pointer_cast<GameSession>(session);
	
	auto broadcastType = pkt.type();

	return true;
}

bool Handle_C_PONG(PacketSessionRef& session, Protocol::C_PONG& pkt)
{
	GameSessionRef gameSession = static_pointer_cast<GameSession>(session);

	gameSession->SetPingTick();
	return true;
}

bool Handle_C_ACTION(PacketSessionRef& session, Protocol::C_ACTION& pkt)
{
	GameSessionRef gameSession = static_pointer_cast<GameSession>(session);

	if (auto room = gameSession->mMyPlayer->mRoom.lock())
	{
		room->DoAsync(&Room::ApplyMove, pkt);
	}

	return true;
}


bool Handle_C_ATTACK(PacketSessionRef& session, Protocol::C_ATTACK& pkt)
{
	GameSessionRef gameSession = static_pointer_cast<GameSession>(session);

	if (auto room = gameSession->mMyPlayer->mRoom.lock())
	{
		room->DoAsync(&Room::ApplyPlayerBomb, gameSession->mMyPlayer);
	}

	return true;
}


bool Handle_C_EXPLODE_BOMB(PacketSessionRef& session, Protocol::C_EXPLODE_BOMB& pkt)
{
	GameSessionRef gameSession = static_pointer_cast<GameSession>(session);

	if (auto room = gameSession->mMyPlayer->mRoom.lock())
	{
		room->DoAsync(&Room::ApplyExplodeBomb, pkt.bombid());
	}


	return true;
}