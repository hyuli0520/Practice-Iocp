#include "pch.h"
#include "ThreadManager.h"
#include "Listener.h"
#include "Service.h"
#include "Allocator.h"
#include "Job.h"
#include "DBConnectionPool.h"
#include "LoginSession.h"
#include "LoginServerPacketHandler.h"

std::wstring CtoW(const char* src) {
	return std::wstring(src, src + strlen(src));
}

enum
{
	WORKER_TICK = 64,
};

void DoWorkerJob(ServerServiceRef& service)
{
	while (true)
	{
		LEndTickCount = ::GetTickCount64() + WORKER_TICK;

		// ��Ʈ��ũ ����� ó�� -> �ΰ��� �������� (��Ŷ �ڵ鷯�� ����)
		service->GetIocpCore()->Dispatch(10);

		// ����� �ϰ� ó��
		ThreadManager::DistributeReservedJobs();

		// �۷ι� ť
		ThreadManager::DoGlobalQueueWork();
	}
}

int main()
{
	ASSERT_CRASH(GDBConnectionPool->Connect(1));

	LoginServerPacketHandler::Init();

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
	ServerServiceRef service = MakeShared<ServerService>(
		NetAddress(CtoW(host), 7777),
		MakeShared<IocpCore>(),
		[]() {return MakeShared<LoginSession>(); },
		10);

	ASSERT_CRASH(service->Start());

	for (int32 i = 0; i < 5; i++)
	{
		GThreadManager->Launch([&service]()
			{
				while (true)
				{
					DoWorkerJob(service);
				}
			});
	}

	// Main Thread
	DoWorkerJob(service);

	GThreadManager->Join();
}