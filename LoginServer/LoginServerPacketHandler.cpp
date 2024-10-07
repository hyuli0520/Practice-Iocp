#include "pch.h"
#include "LoginServerPacketHandler.h"
#include "ServerPacketHandler.h"
#include "LoginSession.h"

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
	
	// 데이터 베이스 처리
	{
		bool success = loginSession->Response(pkt.name(), pkt.password());
		
		if (success)
		{
			// 게임 서버에 입장시키기	
			Protocol::C_ENTER_GAME cEnterGame;
			ServerPacketHandler::Handle_C_ENTER_GAME(session, cEnterGame);
		}
		else
		{
			return false;
		}
	}

	return true;
}
