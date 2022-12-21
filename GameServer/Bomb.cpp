#include "pch.h"
#include "Bomb.h"

Bomb::~Bomb()
{
}

void Bomb::Update()
{
}

void Bomb::Spawn(RoomRef room)
{
	Actor::Spawn(room);
}

void Bomb::SetDetailType(Protocol::Actor* actor)
{
}

bool Bomb::IsInRange(ActorRef actor)
{
	auto [myX, myY] = mPos;
	auto [destX, destY] = actor->mPos;

	float fDistanceX = fabsf(myX - destX);
	float fDistanceY = fabsf(myY - destY);

	if (fDistanceY == 0 && fDistanceX <= mPower * 32.f)
	{
		return true;
	}

	if (fDistanceX == 0 && fDistanceY <= mPower * 32.f)
	{
		return true;
	}

	return false;
}