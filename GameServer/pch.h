#pragma once

#define WIN32_LEAN_AND_MEAN // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.

#ifdef _DEBUG
#pragma comment(lib, "ServerCore\\Debug\\ServerCore.lib")
#pragma comment(lib, "Protobuf\\Debug\\libprotobufd.lib")
#else
#pragma comment(lib, "ServerCore\\Release\\ServerCore.lib")
#pragma comment(lib, "Protobuf\\Release\\libprotobuf.lib")
#endif

#include <fstream>
#include <sstream>

#include "CorePch.h"
#include "Enum.pb.h"

#include "GameTypes.h"

using GameSessionRef = shared_ptr<class GameSession>;
using ActorRef = shared_ptr<class Actor>;
using BombRef = shared_ptr<class Bomb>;

using PlayerRef = shared_ptr<class Player>;
using RoomRef = shared_ptr<class Room>;