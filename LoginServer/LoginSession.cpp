#include "pch.h"
#include "LoginSession.h"

void LoginSession::OnConnected()
{
	auto session = std::static_pointer_cast<PacketSession>(shared_from_this());

	Protocol::C_LOGIN cLogin;
	bool success = LoginServerPacketHandler::Handle_C_LOGIN_GAME(session, cLogin);

	if (!success)
	{
		cout << "Fail to Login Game" << endl;
		return;
	}
}

void LoginSession::OnDisconnected()
{
}

void LoginSession::OnRecvPacket(BYTE* buffer, int32 len)
{
	PacketSessionRef session = GetPacketSessionRef();
	PacketHeader* header = reinterpret_cast<PacketHeader*>(buffer);

	LoginServerPacketHandler::HandlePacket(session, buffer, len);
}

void LoginSession::OnSend(int32 len)
{
}

bool LoginSession::Response(string name, string pw)
{
	DBConnection* dbConn = GDBConnectionPool->Pop();
	mysqlx::Table table = dbConn->GetTable("player");
	auto result = dbConn->Select(table, "player_name", "password");
	for (mysqlx::Row row : result)
	{
		if (row[0].get<string>() == name)
		{
			cout << "id is found" << endl;
			if (row[1].get<string>() == pw)
			{
				cout << "login is success" << endl;
			}
			else
			{
				cout << "pw is not correct" << endl;
				return false;
			}
		}
	}
	GDBConnectionPool->Push(dbConn);

	return true;
}
