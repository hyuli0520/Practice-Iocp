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

	template<typename... Args>
	mysqlx::RowResult Select(mysqlx::Table table, Args... args)
	{
		try
		{
			auto result = table.select(args...).execute();
			return result;
		}
		catch (const mysqlx::Error& err)
		{
			cout << "An error occured : " << err.what() << endl;
		}
	}
};
