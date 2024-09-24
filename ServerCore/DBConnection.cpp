#include "pch.h"
#include "DBConnection.h"
#include "DBConnectionPool.h"

/*-----------------
	DBConnection
-----------------*/

void DBConnection::InitMysql()
{
	const char* url = ("mysqlx://root:1234@127.0.0.1");
	cout << "Creating session on " << url << "..." << endl;
	_session = make_unique<mysqlx::Session>(url);

	cout << "Session accepted, getting schemas..." << endl;
	_schema = make_unique<mysqlx::Schema>(_session->getSchema("sunnight"));
}

bool DBConnection::Connect()
{
	try
	{
		InitMysql();

		// 예시 코드
		/*mysqlx::Table table = GetTable("player");

		{
			auto insert = table.insert("player_id", "player_name", "player_location")
				.values(2, "admin2", "10010").execute();
		}

		auto result = Select(table, "player_id", "player_name");

		for (mysqlx::Row row : result)
		{
			cout << "player_id: " << row[0] << endl;
			if (row[1].get<std::string>() == "admin")
			{
				cout << row[1] << " name is found" << endl;
			}
		}*/
	}
	catch (const mysqlx::Error& err)
	{
		cout << "An error occured : " << err.what() << endl;
		return false;
	}

	return true;
}

void DBConnection::Clear()
{

}

bool DBConnection::Execute()
{
	return false;
}