#pragma once
#include "Protocol.pb.h"

using PacketHandlerFunc = std::function<bool(PacketSessionRef&, BYTE*, int32)>;
extern PacketHandlerFunc GPacketHandler[UINT16_MAX];

bool Handle_INVALID(PacketSessionRef& session, BYTE* buffer, int32 len);

class ServerPacketHandler
{
public:
	static void Init()
	{
		for (int32 i = 0; i < UINT16_MAX; i++)
			GPacketHandler[i] = Handle_INVALID;
		GPacketHandler[Protocol::PacketId::PKT_C_ENTER_GAME] = [](PacketSessionRef& session, BYTE* buffer, int32 len) {return HandlePacket<Protocol::C_ENTER_GAME>(Handle_C_ENTER_GAME, session, buffer, len); };
		GPacketHandler[Protocol::PacketId::PKT_REQUEST_ENTER] = [](PacketSessionRef& session, BYTE* buffer, int32 len) {return HandlePacket<Protocol::REQUEST_ENTER_GAME>(Handle_REQUEST_ENTER, session, buffer, len); };
	}

	static bool HandlePacket(PacketSessionRef& session, BYTE* buffer, int32 len)
	{
		PacketHeader* header = reinterpret_cast<PacketHeader*>(buffer);
		return GPacketHandler[header->id](session, buffer, len);
	}

	// 받기
	static bool Handle_C_ENTER_GAME(PacketSessionRef& session, Protocol::C_ENTER_GAME& pkt);
	static bool Handle_C_LEAVE_GAME(PacketSessionRef& session, Protocol::C_LEAVE_GAME& pkt);

	static bool Handle_C_MOVE(PacketSessionRef& session, Protocol::C_MOVE& pkt);

	static bool Handle_C_CHAT(PacketSessionRef& session, Protocol::C_CHAT& pkt);

	static bool Handle_REQUEST_ENTER(PacketSessionRef& session, Protocol::REQUEST_ENTER_GAME& pkt);

	template<typename PacketType, typename ProcessFunc>
	static bool HandlePacket(ProcessFunc func, PacketSessionRef& session, BYTE* buffer, int32 len)
	{
		PacketType pkt;
		if (pkt.ParseFromArray(buffer + sizeof(PacketHeader), len - sizeof(PacketHeader)) == false)
			return false;

		return func(session, pkt);
	}

	// 보내기
	template<typename T>
	static SendBufferRef MakeSendBuffer(T& pkt, Protocol::PacketId id)
	{
		const uint16 dataSize = static_cast<uint16>(pkt.ByteSizeLong());
		const uint16 packetSize = dataSize + sizeof(PacketHeader);

		SendBufferRef sendBuffer =  MakeShared<SendBuffer>(packetSize);
		PacketHeader* header = reinterpret_cast<PacketHeader*>(sendBuffer->Buffer());
		header->size = packetSize;
		header->id = id;
		ASSERT_CRASH(pkt.SerializeToArray(sendBuffer->Buffer() + 4, dataSize));
		sendBuffer->Close(packetSize);

		return sendBuffer;
	}
};


// https://minusi.tistory.com/entry/%EA%B5%AC%EA%B8%80-%ED%94%84%EB%A1%9C%ED%86%A0%EC%BD%9C-%EB%B2%84%ED%8D%BC-%EC%82%AC%EC%9A%A9%ED%95%98%EA%B8%B0with-visual-studio