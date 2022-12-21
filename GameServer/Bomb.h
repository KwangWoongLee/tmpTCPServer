#pragma once
#include "GameTypes.h"
#include "Actor.h"
#include "Protocol.pb.h"
#include "Bomb.h"
#include "GameSession.h"

class Bomb : public Actor
{
public:
	Bomb(GameSessionRef ownerSession)
	{
		mType = Protocol::ActorType::ACTOR_TYPE_BOMB;
		mHeightSize = 25;
		mWidthSize = 23;
		
		mPlayer = ownerSession->mMyPlayer;
	};
	virtual ~Bomb();

	virtual void Update() override;
	virtual void Spawn(RoomRef room) override;
	virtual void SetDetailType(Protocol::Actor* actor) override;

	bool IsInRange(ActorRef actor);

	weak_ptr<Player> mPlayer;

	uint8 mPower = 1;
};

