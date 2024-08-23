#include "pch.h"
#include "CoreGlobal.h"
#include "ThreadManager.h"
#include "Memory.h"
#include "GlobalQueue.h"
#include "JobTimer.h"

ThreadManager* GThreadManager = nullptr;
Memory* GMemory = nullptr;
GlobalQueue* GGlobalQueue = nullptr;
JobTimer* GJobTimer = nullptr;

class CoreGlobal
{
public:
	CoreGlobal()
	{
		GThreadManager = new ThreadManager();
		GMemory = new Memory();
		GGlobalQueue = new GlobalQueue();
		GJobTimer = new JobTimer();
	}

	~CoreGlobal()
	{
		delete GThreadManager;
		delete GMemory;
		delete GGlobalQueue;
		delete GJobTimer;
	}
}GCoreGlobal;