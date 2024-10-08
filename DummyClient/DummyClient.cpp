#include "pch.h"
#include <iostream>
#include "ThreadManager.h"
#include "Service.h"
#include "Session.h"
#include "ClientPacketHandler.h"

// 클라
// 1) 소켓 생성 (socket)
// 2) 서버에 연결 요청 (connect)
// 3) 통신

char sendData[] = "Hello World";

class ServerSession : public PacketSession
{
public:
	~ServerSession()
	{
		cout << "~ServerSession" << endl;
	}

	virtual void OnConnected() override
	{
		Protocol::C_LOGIN pkt;
		auto sendBuffer = ClientPacketHandler::MakeSendBuffer(pkt, Protocol::PacketId::PKT_C_LOGIN);
		Send(sendBuffer);
	}

	virtual void OnRecvPacket(BYTE* buffer, int32 len) override
	{
		PacketSessionRef session = GetPacketSessionRef();
		PacketHeader* header = reinterpret_cast<PacketHeader*>(buffer);
		
		ClientPacketHandler::HandlePacket(session, buffer, len);
	}

	virtual void OnSend(int32 len) override
	{
		//cout << "OnSend Len = " << len << endl;
	}

	virtual void OnDisconnected() override
	{
		//cout << "Disconnected" << endl;
	}
};	

std::wstring CtoW(const char* src) {
	return std::wstring(src, src + strlen(src));
}

int main()
{
	SocketUtils::Init();

	this_thread::sleep_for(1s);

	char buf[128] = "";
	gethostname(buf, sizeof(buf));
	auto entry = gethostbyname(buf);
	if (entry == nullptr)
		return 0;

	SOCKADDR_IN addr_in = { };
	for (int i = 0; entry->h_addr_list[i] != nullptr; ++i)
	{
		addr_in.sin_family = AF_INET;
		addr_in.sin_addr.s_addr = *reinterpret_cast<long*>(entry->h_addr_list[i]);
	}

	auto host = inet_ntoa(addr_in.sin_addr);
	cout << host << endl;
	ClientServiceRef service = MakeShared<ClientService>(
		NetAddress(CtoW(host), 7777),
		MakeShared<IocpCore>(),
		[]() { return MakeShared<ServerSession>(); }, // TODO : SessionManager 등
		1);

	ASSERT_CRASH(service->Start());

	for (int32 i = 0; i < 5; i++)
	{
		GThreadManager->Launch([=]()
			{
				while (true)
				{
					service->GetIocpCore()->Dispatch();
				}
			});
	}

	string input;
	Protocol::C_CHAT cChat;
	
	while (true)
	{
		cin >> input;
	
		cChat.set_msg(input);

		auto sendBuffer = 
			ClientPacketHandler::MakeSendBuffer(cChat, Protocol::PacketId::PKT_C_CHAT);

		service->Broadcast(sendBuffer);
	}
	GThreadManager->Join();
}

