#include "pch.h"
#include "LoginSession.h"

void LoginSession::OnConnected()
{
}

void LoginSession::OnDisconnected()
{
}

void LoginSession::OnRecvPacket(BYTE* buffer, int32 len)
{
	PacketSessionRef session = GetPacketSessionRef();
	PacketHeader* header = reinterpret_cast<PacketHeader*>(buffer);

	LoginServerPacketHandler::HandlePacket(session, buffer, len);

	char recvBuffer[4096];
	::memcpy(recvBuffer, &buffer[4], header->size - sizeof(PacketHeader));
	cout << "RecvBuffer : " << recvBuffer << endl;

	Protocol::C_LOGIN cLogin;
	auto success = LoginServerPacketHandler::Handle_C_LOGIN_GAME(session, cLogin);

	cout << "RecvMessage : " << buffer << endl;
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
