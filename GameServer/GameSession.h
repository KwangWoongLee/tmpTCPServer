#pragma once
#include "Session.h"

class GameSession : public PacketSession
{
public:
	~GameSession()
	{
		cout << "~GameSession" << endl;
	}

	virtual void OnConnected() override;
	virtual void OnDisconnected() override;
	virtual void OnRecvPacket(BYTE* buffer, int32 len) override;
	virtual void OnSend(int32 len) override;

	void PingCheck();
	void SetPingTick() { mLastPingTick = GetTickCount64(); };

public:
	PlayerRef mMyPlayer;
	weak_ptr<Room> mRoom;
	uint64					mAccountIdx = 0;
	uint64 mLastPingTick{};
};