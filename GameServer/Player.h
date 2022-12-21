#pragma once
#include "GameTypes.h"
#include "Actor.h"
#include "Protocol.pb.h"
#include "Bomb.h"

class Player : public PlayersActor
{
public:
	Player(GameSessionRef ownerSession)
		:PlayersActor(ownerSession)
	{
		mType = Protocol::ActorType::ACTOR_TYPE_PLAYER;
		mHeightSize = 25;
		mWidthSize = 23;
	};
	virtual ~Player();
	
	virtual void Update() override;
	virtual void Spawn(RoomRef room) override;
	virtual void SetDetailType(Protocol::Actor* actor) override;

	Position SearchBombPosition();

	Protocol::PlayerType    mPlayerType = Protocol::PlayerType::PLAYER_TYPE_NONE;

	Vector<BombRef> mBombs;
	
};

