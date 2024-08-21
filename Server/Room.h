#pragma once
#include "JobQueue.h"

class Room : public JobQueue
{
	friend class EnterJob;
	friend class LeaveJob;
	friend class BroadCastJob;

public:
	Room();
	virtual ~Room();

	// 싱글쓰레드 환경인마냥 코딩
	bool HandleEnterPlayer(PlayerRef player);
	bool HandleLeavePlayer(PlayerRef player);

	void HandleMove(Protocol::C_MOVE &pkt);

	void HandleChat(Protocol::C_CHAT& pkt);

	void BroadCast(SendBufferRef sendBuffer, uint64 exceptId = 0);

private:
	bool EnterPlayer(PlayerRef player);
	bool LeavePlayer(uint64 objectId);

private:
	unordered_map<uint64, PlayerRef> _players;
};

extern RoomRef GRoom;