#include "pch.h"
#include "RoomManager.h"

#include "Room.h"
#include "Actor.h"
#include "GameSession.h"

Atomic<uint8> RoomManager::smRoomId = 1;
shared_ptr<RoomManager> GRoomManager = make_shared<RoomManager>();

void RoomManager::Add(uint8 gameMapId)
{
	uint8 roomId = smRoomId++;
	
	auto roomRef = MakeShared<Room>(roomId, GameMap(gameMapId));
	roomRef->Init();

	mId2Room[roomId] = roomRef;
}

void RoomManager::Remove(uint8 roomId)
{
	mId2Room.erase(roomId);
}

void RoomManager::BroadCast(SendBufferRef sendBuffer)
{
	for (auto& [id, room] : mId2Room)
	{
		room->DoAsync(&Room::Broadcast, sendBuffer);
	}
}

RoomRef RoomManager::Find(uint8 roomId) 
{
	auto iter = mId2Room.find(roomId);
	if (iter == mId2Room.end())
		return nullptr;

	return iter->second;
}


void RoomManager::HandleEnterGame(uint8 roomId, ActorRef actor)
{
	auto room = Find(roomId);

	room->DoAsync(&Room::Enter, actor, true);
}

void RoomManager::Update()
{
	for (auto& [id, room] : mId2Room)
	{
		room->DoAsync(&Room::Update);
	}

}