#pragma once
#include <sql.h>
#include <sqlext.h>

/*-----------------
	DBConnection
-----------------*/

class DBConnection
{
public:
	bool Connect();
	void Clear();

	bool Execute();
};

