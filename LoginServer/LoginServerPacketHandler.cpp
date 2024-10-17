#include "pch.h"

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
	
	// 单捞磐 海捞胶 贸府
	{
		//bool success = loginSession->Response(pkt.name(), pkt.password());
		bool success = loginSession->Response("admin", "1234");
		
		if (success)
		{
			Protocol::SUCCESS_LOGIN successPkt;
			auto successSendBuffer = MakeSendBuffer(successPkt, Protocol::PacketId::PKT_SUCCESS_LOGIN);
			session->Send(successSendBuffer);
		}
		else
		{
			return false;
		}
	}

	return true;
}
