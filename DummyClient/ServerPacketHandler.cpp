#include "pch.h"
#include "ServerPacketHandler.h"
#include "ServerSession.h"

PacketHandlerFunc GPacketHandler[UINT16_MAX];

// 직접 컨텐츠 작업자

bool Handle_INVALID(PacketSessionRef& session, BYTE* buffer, int32 len)
{
	PacketHeader* header = reinterpret_cast<PacketHeader*>(buffer);
	// TODO : Log
	return false;
}
//
//bool Handle_S_LOGIN(PacketSessionRef& session, Protocol::S_LOGIN& pkt)
//{
//	if (pkt.success() == false)
//		return true;
//
//	if (pkt.players().size() == 0)
//	{
//		// 캐릭터 생성창
//	}
//
//	// 입장 UI 버튼 눌러서 게임 입장
//	Protocol::C_ENTER_GAME enterGamePkt;
//	enterGamePkt.set_playerindex(0); // 첫번째 캐릭터로 입장
//	auto sendBuffer = ServerPacketHandler::MakeSendBuffer(enterGamePkt);
//	session->Send(sendBuffer);
//
//	return true;
//}

bool Handle_S_ENTER_GAME(PacketSessionRef& session, Protocol::S_ENTER_GAME& pkt)
{
	// TODO
	if (pkt.success() == false)
	{
		//입장에러 처리
		return true;
	}

	//맵정보 읽기
	//pkt->

	// 입장 UI 버튼 눌러서 게임 입장
	Protocol::C_BROADCAST_ROOM broadCastPkt;
	broadCastPkt.set_type(Protocol::BroadCastType::BROADCAST_ENTER_GAME);
	auto sendBuffer = ServerPacketHandler::MakeSendBuffer(broadCastPkt);
	session->Send(sendBuffer);

	return true;
}

bool Handle_S_BROADCAST_ROOM(PacketSessionRef& session, Protocol::S_BROADCAST_ROOM& pkt)
{

	return true;
}

bool Handle_S_PING(PacketSessionRef& session, Protocol::S_PING& pkt)
{
	return false;
}
