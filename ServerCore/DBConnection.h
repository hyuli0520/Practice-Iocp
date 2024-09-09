#pragma once
#include <sql.h>
#include <sqlext.h>

/*-----------------
	DBConnection
-----------------*/

class DBConnection
{
public:
	DBConnection() = default;
	void InitMysql();

	bool Connect();
	void Clear();

	bool Execute();

	mysqlx::Table GetTable(string schemaName)
	{
		try
		{
			auto table = _schema->getTable(schemaName);
			cout << "Successful get table " << schemaName << endl;
			return table;
		}
		catch (const mysqlx::Error& err)
		{
			cout << "An error occured : " << err.what() << endl;
		}
	}

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

private:
	unique_ptr<mysqlx::Schema> _schema;
	unique_ptr<mysqlx::Session> _session;
};
