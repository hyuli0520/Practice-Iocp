#include "pch.h"
#include "GameSession.h"
#include "GameSessionManager.h"
#include "Player.h"
#include "ObjectUtils.h"
#include <iomanip>

void GameSession::OnConnected()
{
	GSessionManager.Add(static_pointer_cast<GameSession>(shared_from_this()));

	{
		DBConnection* dbConn = GDBConnectionPool->Pop();
		mysqlx::Table table = dbConn->GetTable("player");
		auto result = dbConn->Select(table, "player_id");
		
		for (mysqlx::Row row : result)
		{
			cout << row[0] << endl;
		}

		GDBConnectionPool->Push(dbConn);
	}
}

void GameSession::OnDisconnected()
{
	GSessionManager.Remove(static_pointer_cast<GameSession>(shared_from_this()));

	Protocol::C_LEAVE_GAME cLeaveGame;
	auto session = std::static_pointer_cast<PacketSession>(shared_from_this());
	auto success = ServerPacketHandler::Handle_C_LEAVE_GAME(session, cLeaveGame);

	if (success == false)
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
	
	char recvBuffer[4096];
	::memcpy(recvBuffer, &buffer[4], header->size - sizeof(PacketHeader));
	cout << "RecvBuffer : " << recvBuffer << endl;

	cout << "OnRecv Len = " << len << endl;
}

void GameSession::OnSend(int32 len)
{
}