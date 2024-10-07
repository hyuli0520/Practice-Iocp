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
	auto session = std::static_pointer_cast<PacketSession>(shared_from_this());
	auto success = LoginServerPacketHandler::Handle_C_LOGIN_GAME(session, cLogin);

	cout << "RecvMessage : " << buffer << endl;
}

void LoginSession::OnSend(int32 len)
{
}

bool LoginSession::Response()
{
	DBConnection* dbConn = GDBConnectionPool->Pop();
	mysqlx::Table table = dbConn->GetTable("player");
	auto result = dbConn->Select(table, "player_name", "password");
	for (mysqlx::Row row : result)
	{
		if (row[0].get<string>() == _name)
		{
			cout << "id is found" << endl;
			if (row[1].get<string>() == _pw)
			{
				cout << "login is success" << endl;
			}
		}
	}
	GDBConnectionPool->Push(dbConn);

	return true;
}
