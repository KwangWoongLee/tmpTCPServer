#include "pch.h"
#include "GameManager.h"
#include "RoomManager.h"
#include "Protocol.pb.h"
#include "ClientPacketHandler.h"
#include "GameSession.h"

Atomic<uint64> GameManager::idGenerator = 1;
shared_ptr<GameManager> GGameManager = make_shared<GameManager>();


void GameManager::Update()
{
	GRoomManager->Update();
}

void GameManager::Ping(GameSessionRef session)
{
	session->PingCheck();

	Protocol::S_PING pingPkt;

	auto pingBuffer = ClientPacketHandler::MakeSendBuffer(pingPkt);
	session->Send(pingBuffer);

	GGameManager->DoTimer(5000, &GameManager::Ping, session);
}