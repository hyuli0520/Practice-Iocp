#include "pch.h"
#include "CoreGlobal.h"
#include "ThreadManager.h"
#include "GlobalQueue.h"

ThreadManager* GThreadManager = nullptr;
GlobalQueue* GGlobalQueue = nullptr;

class CoreGlobal
{
public:
	CoreGlobal()
	{
		GThreadManager = new ThreadManager();
		GGlobalQueue = new GlobalQueue();
	}

	~CoreGlobal()
	{
		delete GThreadManager;
		delete GGlobalQueue;
	}
}GCoreGlobal;