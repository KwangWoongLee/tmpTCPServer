#pragma once

class GameManager : public JobQueue
{
public:
	void Update();

	void Ping(GameSessionRef session);

	static Atomic<uint64> idGenerator;

private:

};

extern shared_ptr<GameManager> GGameManager;