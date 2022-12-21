#pragma once
#include "GameTypes.h"
#include "GameManager.h"

class Actor : public enable_shared_from_this<Actor>
{
public:
	virtual void Update() = 0;
	void SetStartPosition(Position pos, bool randPos = false);

	virtual void Spawn(RoomRef room) {
		mId = GGameManager->idGenerator++;
		mRoom = room;
	};
	virtual void SetDetailType(Protocol::Actor* actor) = 0;


public:
	uint64					mId{};
	string					mName{};
	Position				mPos{};
	weak_ptr<Room>			mRoom;

	uint16					mHeightSize = 0;
	uint16					mWidthSize = 0;

	Protocol::ActorType		mType = Protocol::ActorType::ACTOR_TYPE_NONE;

};

class PlayersActor : public Actor
{
public:
	PlayersActor(GameSessionRef ownerSession) 
		:Actor(), mOwnerSession(ownerSession)
	{}

	GameSessionRef			mOwnerSession = nullptr;
};

class BGActor : public Actor
{
public:
	BGActor()
		:Actor()
	{}

	virtual void Update() {};
	virtual void SetDetailType(Protocol::Actor* actor) {};
};

