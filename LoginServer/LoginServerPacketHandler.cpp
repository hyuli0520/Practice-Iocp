#include "pch.h"
#include "ServerPacketHandler.h"

PacketHandlerFunc GPacketHandler[UINT16_MAX];

bool Handle_INVALID(PacketSessionRef& session, BYTE* buffer, int32 len)
{
	PacketHeader* header = reinterpret_cast<PacketHeader*>(buffer);
	// TODO : Log
	return false;
}

bool LoginServerPacketHandler::Handle_C_LOGIN_GAME(PacketSessionRef& session, Protocol::C_LOGIN& pkt)
{
	auto loginSession = static_pointer_cast<LoginSession>(session);
	
	// ������ ���̽� ó��
	{
		//bool success = loginSession->Response(pkt.name(), pkt.password());
		bool success = loginSession->Response("admin", "1234");
		
		if (success)
		{
			// ���� ������ �����Ű��	
			Protocol::C_ENTER_GAME cEnterGame;
			auto sendBuffer = MakeSendBuffer(cEnterGame, Protocol::PacketId::PKT_C_ENTER_GAME);
			session->Send(sendBuffer);
		}
		else
		{
			return false;
		}
	}

	return true;
}
