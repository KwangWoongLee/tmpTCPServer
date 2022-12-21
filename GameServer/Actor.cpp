#include "pch.h"
#include "Actor.h"

void Actor::SetStartPosition(Position pos, bool randPos)
{
	if (randPos)
	{
		std::vector<Position> startPositions = { {0.f * 32, 0.f * 32}, {1.f * 32,11.f * 32} , {10.f * 32 ,0.f * 32} , {11.f * 32,11.f * 32} };

		auto rand4 = rand() % 4;
		mPos = startPositions[rand4];
	}
	else
	{
		mPos = pos;
	}
	
}
