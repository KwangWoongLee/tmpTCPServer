#pragma once

class RoomManager : public JobQueue
{
public:
	void Add(uint8 gameMapId);
	void Remove(uint8 roomId);
	void BroadCast(SendBufferRef sendBuffer);
	RoomRef Find(uint8 roomId);

	void HandleEnterGame(uint8 roomId, ActorRef actor);

	void Update();


	static Atomic<uint8> smRoomId;
private:

	Map<uint8, RoomRef> mId2Room;
};

extern shared_ptr<RoomManager> GRoomManager;