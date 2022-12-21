#include "pch.h"
#include "GameMap.h"
#include "Block.h"

GameMap::GameMap(uint8 id)
	: mId(id)
{
}

#pragma region 이동
bool GameMap::ApplyMove(ActorRef actor, Position dest)
{
	if (actor == nullptr)
		return false;

	if (canGo(actor, dest) == false)
		return false;

	actor->mPos = dest;
	return true;
}

bool GameMap::canGo(ActorRef actor, Position dest)
{
	auto [x, y] = dest;
	if (actor->mPos == dest)
		return false;

	if (isInRange(dest) == false)
		return false;

	if (auto room = mRoom.lock())
		if (room->IsCollision(actor, dest))
			return false;

	return true;
}

bool GameMap::isInRange(Position dest)
{
	return mMapRange[0] * 32 <= dest.first  && dest.first < mMapRange[1] * 33 && mMapRange[2] * 32 <= dest.second && dest.second < mMapRange[3] * 30;
}

#pragma endregion


#pragma region 초기화
void GameMap::Init(RoomRef room)
{
	mRoom = room;

	loadData();
	spawnMapActor();
}

bool GameMap::loadData(std::string_view mapFileName, std::string_view collisionFileName)
{
	ifstream mapfile(mapFileName.data());
	if (true == mapfile.fail())
	{
		//파일 읽기실패 TODO:로그 예외처리
		return false;
	}

	ifstream collisionFile(collisionFileName.data());
	if (true == collisionFile.fail())
	{
		//파일 읽기실패 TODO:로그 예외처리
		return false;
	}



	string cell;
	string line;

	for (auto i = 0; i < 4; ++i)
	{
		getline(mapfile, line);
		stringstream lineStream(line);
		getline(lineStream, cell, ',');
		mMapRange.push_back(stoi(cell));
	}

	mMap.reserve(mMapRange[3]);
	mMapCollision.reserve(mMapRange[3]);

	while (getline(mapfile, line))
	{
		auto maxX = mMapRange[1];
		vector<short> row;
		row.reserve(maxX);
		stringstream lineStream(line);


		while (getline(lineStream, cell, ','))
		{
			row.push_back((short)stoi(cell));
		}

		mMap.push_back(row);
	}

	while (getline(collisionFile, line))
	{
		auto maxX = mMapRange[1];
		vector<short> row;
		row.reserve(maxX);
		stringstream lineStream(line);


		while (getline(lineStream, cell, ','))
		{
			row.push_back((short)stoi(cell));
		}

		mMapCollision.push_back(row);
	}

	return true;
}

void GameMap::spawnMapActor()
{
	for (auto i = 0; i < mMap.size(); ++i)
		for (auto j = 0; j < mMap[0].size(); ++j)
		{
			auto blockType = static_cast<Protocol::BlockType>(mMap[i][j]);
			if (blockType == Protocol::BlockType::BLOCK_TYPE_NONE)
				continue;

			ActorRef actorRef = MakeShared<Block>(blockType);
			actorRef->mName = "";
			actorRef->mType = Protocol::ActorType::ACTOR_TYPE_BLOCK;

			actorRef->SetStartPosition({ i * 32,j * 32 });

			if (auto room = mRoom.lock())
				room->DoAsync(&Room::Enter, actorRef, false);
		}

}
#pragma endregion
