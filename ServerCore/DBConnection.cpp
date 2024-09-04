#include "pch.h"
#include "DBConnection.h"
#include "DBConnectionPool.h"

/*-----------------
	DBConnection
-----------------*/

bool DBConnection::Connect()
{
	try
	{
		const char* url = ("mysqlx://root:1234@127.0.0.1");
		cout << "Creating session on" << url << "..." << endl;
		mysqlx::Session session(url);

		cout << "Session accepted, getting collections..." << endl;
		mysqlx::Schema schema = session.getSchema("sunnight");
		mysqlx::Table table = schema.getTable("player");


		//{
		//	auto insert = table.insert("player_id", "player_name", "player_location")
		//		.values(2, "admin2", "10010").execute();
		//}
		
		auto result = Select(table, "player_id", "player_name", "player_location");

		for (mysqlx::Row row : result)
			cout << "player_id: " << row[0] 
				 << ", player_name: " << row[1] 
				 << ", player_location: " << row[2] << endl;

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