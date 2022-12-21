#include "pch.h"
#include "GameSession.h"
#include "GameSessionManager.h"
#include "ClientPacketHandler.h"
#include "Room.h"
#include "RoomManager.h"
#include "GameManager.h"
#include "Player.h"

void GameSession::OnConnected()
{
	GSessionManager.Add(static_pointer_cast<GameSession>(shared_from_this()));

	{
		Protocol::S_PING pingPkt;

		auto pingBuffer = ClientPacketHandler::MakeSendBuffer(pingPkt);
		Send(pingBuffer);

		GGameManager->DoTimer(5000, &GameManager::Ping, static_pointer_cast<GameSession>(shared_from_this()));
	}
	
	mLastPingTick = GetTickCount64();
}

void GameSession::OnDisconnected()
{
	GSessionManager.Remove(static_pointer_cast<GameSession>(shared_from_this()));

	if (mMyPlayer)
	{
		if (auto room = mMyPlayer->mRoom.lock())
		{
			ActorRef actorRef = mMyPlayer;
			room->DoAsync(&Room::Leave, actorRef);
		}
			
	}

	mMyPlayer = nullptr;
}

void GameSession::OnRecvPacket(BYTE* buffer, int32 len)
{
	PacketSessionRef session = GetPacketSessionRef();
	PacketHeader* header = reinterpret_cast<PacketHeader*>(buffer);

	// TODO : packetId 대역 체크
	ClientPacketHandler::HandlePacket(session, buffer, len);
}

void GameSession::OnSend(int32 len)
{
}

void GameSession::PingCheck()
{
	if (mLastPingTick > 0)
	{
		auto delta = (GetTickCount64() - mLastPingTick);
		if (delta > 30 * 1000)
		{
			Disconnect(L"Disconnected by PingCheck");
			return;
		}
	}

}

