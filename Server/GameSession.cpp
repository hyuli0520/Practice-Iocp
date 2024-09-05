#include "pch.h"
#include "GameSession.h"
#include "GameSessionManager.h"
#include "Player.h"
#include "ObjectUtils.h"
#include <iomanip>

void GameSession::OnConnected()
{
	GSessionManager.Add(static_pointer_cast<GameSession>(shared_from_this()));

	Protocol::C_ENTER_GAME cEnterGame;
	auto session = std::static_pointer_cast<PacketSession>(shared_from_this());
	auto success = ServerPacketHandler::Handle_C_ENTER_GAME(session, cEnterGame);

	if (success == false)
	{
		cout << "Failed to Enter Game" << endl;
		return;
	}

	{
		DBConnection* dbConn = GDBConnectionPool->Pop();
		mysqlx::Table table = dbConn->GetTable(*dbConn->_schema, "player");
		auto result = dbConn->Select(table, "player_id");

	}

	string input;
	cin >> input;
	Protocol::C_CHAT cChat;
	cChat.set_msg(input);
	ServerPacketHandler::Handle_C_CHAT(session, cChat);
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

	cout << "OnRecv Len = " << len << endl;

	string input;
	cin >> input;
	Protocol::C_CHAT cChat;
	cChat.set_msg(input);
	ServerPacketHandler::Handle_C_CHAT(session, cChat);
}

void GameSession::OnSend(int32 len)
{
}