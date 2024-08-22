#pragma once

#include <thread>
#include <functional>

/*--------------------
	Thread Manager
--------------------*/

class ThreadManager
{
public:
	ThreadManager();
	~ThreadManager();

	void Launch(function<void(void)> callback);
	void Join();

	static void InitTLS();
	static void DestoryTLS();

	static void DoGlobalQueueWork();
	static void DistributeReservedJobs();

private:
	Mutex _lock;
	vector<thread> _threads;
};
