#include "pch.h"
#include "ThreadManager.h"
#include "Listener.h"
#include "Service.h"
#include "GameSessionManager.h"
#include "Allocator.h"
#include "Job.h"
#include "Room.h"
#include "DBConnectionPool.h"

using namespace std;

// 서버
// 1) 새로운 소켓 생성 (socket)
// 2) 소켓에 주소/포트 번호 설정 (bind)
// 3) 소켓 일 시키기 (listen)
// 4) 손님 접속 (accept)
// 5) 클라와 통신

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

		// 네트워크 입출력 처리 -> 인게임 로직까지 (패킷 핸들러에 의해)
		service->GetIocpCore()->Dispatch(10);

		// 예약된 일감 처리
		ThreadManager::DistributeReservedJobs();

		// 글로벌 큐
		ThreadManager::DoGlobalQueueWork();
	}
}

int main()
{

	ServerPacketHandler::Init();


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
		[]() {return MakeShared<GameSession>(); },
		100);

	assert(service->Start());

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