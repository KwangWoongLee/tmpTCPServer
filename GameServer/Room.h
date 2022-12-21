#pragma once
#include "Protocol.pb.h"

#include "JobQueue.h"
#include "GameMap.h"
class Room : public JobQueue
{
public:
	Room() = delete;
	Room(uint8 roomId, GameMap&& map);
	
	~Room() = default;

	void Init();

	RoomRef			GetRoomRef() { return static_pointer_cast<Room>(shared_from_this()); }

	void Enter(ActorRef actor, bool playerEnter = false);
	void Leave(ActorRef actor);
	void Broadcast(SendBufferRef sendBuffer);

	void Update();

	void ApplyMove(Protocol::C_ACTION pkt);
	void ApplyPlayerBomb(PlayerRef bombOwner);
	void ApplyExplodeBomb(uint64 bombId);
	bool IsCollision(ActorRef actor, Position dest);

private:
	Map<uint64, ActorRef> mActorMap;
	Map<uint64, PlayerRef> mPlayerMap;
	GameMap mGameMap;
	uint8 mId;

	ActorRef findActor(uint64 id);
};