#pragma once
#include "GameTypes.h"
#include "Actor.h"
#include "Protocol.pb.h"
#include "Room.h"

class Block : public Actor
{
public:
	Block(Protocol::BlockType blockType)
	{
		mType = Protocol::ActorType::ACTOR_TYPE_BLOCK;
		mBlockType = blockType;

		mHeightSize = 30;
		mWidthSize = 32;
	};
	virtual ~Block();

	virtual void Update() override {};
	virtual void Spawn(RoomRef room) override;
	virtual void SetDetailType(Protocol::Actor* actor) override;

	Protocol::BlockType mBlockType = Protocol::BlockType::BLOCK_TYPE_NONE;
};

