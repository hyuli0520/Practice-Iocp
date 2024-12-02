#include "pch.h"
#include "GameSession.h"
#include "GameSessionManager.h"
#include "Player.h"
#include "ObjectUtils.h"

void GameSession::OnConnected()
{
	GSessionManager.Add(static_pointer_cast<GameSession>(shared_from_this()));
	auto session = GetPacketSessionRef();

	cout << "Connect" << endl;
}

void GameSession::OnDisconnected()
{
	GSessionManager.Remove(static_pointer_cast<GameSession>(shared_from_this()));

	Protocol::C_LEAVE_GAME cLeaveGame;
	auto session = std::static_pointer_cast<PacketSession>(shared_from_this());
	auto success = ServerPacketHandler::Handle_C_LEAVE_GAME(session, cLeaveGame);

	if (!success)
	{
		cout << "Failed to Leave Game" << endl;
		return;
	}
}

void GameSession::OnRecvPacket(BYTE* buffer, int32 len)
{
	auto session = GetPacketSessionRef();
	PacketHeader* header = reinterpret_cast<PacketHeader*>(buffer);

	ServerPacketHandler::HandlePacket(session, buffer, len);
}

void GameSession::OnSend(int32 len)
{
}