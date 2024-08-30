#include "pch.h"
#include "DBConnection.h"

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
		cout << "Session accepted, creating collections..." << endl;

		mysqlx::Schema schema = session.getSchema("sunnight");
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
