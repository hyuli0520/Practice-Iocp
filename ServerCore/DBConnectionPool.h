#pragma once
#include "DBConnection.h"

/*----------------------
	DBConnectionPool
----------------------*/

class DBConnectionPool
{
public:
	DBConnectionPool();
	~DBConnectionPool();

	bool Connect(int32 connectionCount);
	void Clear();

private:
	USE_LOCK;
	Vector<DBConnection*> _connections;
};

