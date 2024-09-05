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

	static mysqlx::Table GetTable(mysqlx::Schema schema, string schemaName)
	{
		try
		{
			auto table = schema.getTable(schemaName);
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

public:
	unique_ptr<mysqlx::Schema> _schema;

};
