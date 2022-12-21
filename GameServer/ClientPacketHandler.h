#pragma once
#include "Protocol.pb.h"

using PacketHandlerFunc = std::function<bool(PacketSessionRef&, BYTE*, int32)>;
extern PacketHandlerFunc GPacketHandler[UINT16_MAX];

enum : uint16
{
	PKT_C_ENTER_GAME = 1000,
	PKT_C_LEAVE_GAME = 1001,
	PKT_S_ENTER_GAME = 1002,
	PKT_S_LEAVE_GAME = 1003,
	PKT_C_BROADCAST_ROOM = 1004,
	PKT_S_ACTION = 1005,
	PKT_S_SPAWN = 1006,
	PKT_S_DESPAWN = 1007,
	PKT_S_PING = 1008,
	PKT_C_PONG = 1009,
	PKT_C_ACTION = 1010,
	PKT_C_ATTACK = 1011,
	PKT_C_EXPLODE_BOMB = 1012,
};

// Custom Handlers
bool Handle_INVALID(PacketSessionRef& session, BYTE* buffer, int32 len);
bool Handle_C_ENTER_GAME(PacketSessionRef& session, Protocol::C_ENTER_GAME& pkt);
bool Handle_C_LEAVE_GAME(PacketSessionRef& session, Protocol::C_LEAVE_GAME& pkt);
bool Handle_C_BROADCAST_ROOM(PacketSessionRef& session, Protocol::C_BROADCAST_ROOM& pkt);
bool Handle_C_PONG(PacketSessionRef& session, Protocol::C_PONG& pkt);
bool Handle_C_ACTION(PacketSessionRef& session, Protocol::C_ACTION& pkt);
bool Handle_C_ATTACK(PacketSessionRef& session, Protocol::C_ATTACK& pkt);
bool Handle_C_EXPLODE_BOMB(PacketSessionRef& session, Protocol::C_EXPLODE_BOMB& pkt);

class ClientPacketHandler
{
public:
	static void Init()
	{
		for (int32 i = 0; i < UINT16_MAX; i++)
			GPacketHandler[i] = Handle_INVALID;
		GPacketHandler[PKT_C_ENTER_GAME] = [](PacketSessionRef& session, BYTE* buffer, int32 len) { return HandlePacket<Protocol::C_ENTER_GAME>(Handle_C_ENTER_GAME, session, buffer, len); };
		GPacketHandler[PKT_C_LEAVE_GAME] = [](PacketSessionRef& session, BYTE* buffer, int32 len) { return HandlePacket<Protocol::C_LEAVE_GAME>(Handle_C_LEAVE_GAME, session, buffer, len); };
		GPacketHandler[PKT_C_BROADCAST_ROOM] = [](PacketSessionRef& session, BYTE* buffer, int32 len) { return HandlePacket<Protocol::C_BROADCAST_ROOM>(Handle_C_BROADCAST_ROOM, session, buffer, len); };
		GPacketHandler[PKT_C_PONG] = [](PacketSessionRef& session, BYTE* buffer, int32 len) { return HandlePacket<Protocol::C_PONG>(Handle_C_PONG, session, buffer, len); };
		GPacketHandler[PKT_C_ACTION] = [](PacketSessionRef& session, BYTE* buffer, int32 len) { return HandlePacket<Protocol::C_ACTION>(Handle_C_ACTION, session, buffer, len); };
		GPacketHandler[PKT_C_ATTACK] = [](PacketSessionRef& session, BYTE* buffer, int32 len) { return HandlePacket<Protocol::C_ATTACK>(Handle_C_ATTACK, session, buffer, len); };
		GPacketHandler[PKT_C_EXPLODE_BOMB] = [](PacketSessionRef& session, BYTE* buffer, int32 len) { return HandlePacket<Protocol::C_EXPLODE_BOMB>(Handle_C_EXPLODE_BOMB, session, buffer, len); };
	}

	static bool HandlePacket(PacketSessionRef& session, BYTE* buffer, int32 len)
	{
		PacketHeader* header = reinterpret_cast<PacketHeader*>(buffer);
		return GPacketHandler[header->id](session, buffer, len);
	}
	static SendBufferRef MakeSendBuffer(Protocol::S_ENTER_GAME& pkt) { return MakeSendBuffer(pkt, PKT_S_ENTER_GAME); }
	static SendBufferRef MakeSendBuffer(Protocol::S_LEAVE_GAME& pkt) { return MakeSendBuffer(pkt, PKT_S_LEAVE_GAME); }
	static SendBufferRef MakeSendBuffer(Protocol::S_ACTION& pkt) { return MakeSendBuffer(pkt, PKT_S_ACTION); }
	static SendBufferRef MakeSendBuffer(Protocol::S_SPAWN& pkt) { return MakeSendBuffer(pkt, PKT_S_SPAWN); }
	static SendBufferRef MakeSendBuffer(Protocol::S_DESPAWN& pkt) { return MakeSendBuffer(pkt, PKT_S_DESPAWN); }
	static SendBufferRef MakeSendBuffer(Protocol::S_PING& pkt) { return MakeSendBuffer(pkt, PKT_S_PING); }

private:
	template<typename PacketType, typename ProcessFunc>
	static bool HandlePacket(ProcessFunc func, PacketSessionRef& session, BYTE* buffer, int32 len)
	{
		PacketType pkt;
		if (pkt.ParseFromArray(buffer + sizeof(PacketHeader), len - sizeof(PacketHeader)) == false)
			return false;

		return func(session, pkt);
	}

	template<typename T>
	static SendBufferRef MakeSendBuffer(T& pkt, uint16 pktId)
	{
		const uint16 dataSize = static_cast<uint16>(pkt.ByteSizeLong());
		const uint16 packetSize = dataSize + sizeof(PacketHeader);

		SendBufferRef sendBuffer = GSendBufferManager->Open(packetSize);
		PacketHeader* header = reinterpret_cast<PacketHeader*>(sendBuffer->Buffer());
		header->size = packetSize;
		header->id = pktId;
		ASSERT_CRASH(pkt.SerializeToArray(&header[1], dataSize));
		sendBuffer->Close(packetSize);

		return sendBuffer;
	}
};