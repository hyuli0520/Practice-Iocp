#include "pch.h"
#include "CoreGlobal.h"
#include "ThreadManager.h"
#include "Memory.h"
#include "GlobalQueue.h"
#include "JobTimer.h"
#include "DBConnectionPool.h"

ThreadManager* GThreadManager = nullptr;
Memory* GMemory = nullptr;
GlobalQueue* GGlobalQueue = nullptr;
JobTimer* GJobTimer = nullptr;

DBConnectionPool* GDBConnectionPool = nullptr;

class CoreGlobal
{
public:
	CoreGlobal()
	{
		GThreadManager = new ThreadManager();
		GMemory = new Memory();
		GGlobalQueue = new GlobalQueue();
		GJobTimer = new JobTimer();
		GDBConnectionPool = new DBConnectionPool();
	}

	~CoreGlobal()
	{
		delete GThreadManager;
		delete GMemory;
		delete GGlobalQueue;
		delete GJobTimer;
		delete GDBConnectionPool;
	}
}GCoreGlobal;