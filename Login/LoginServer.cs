using MySql.Data.MySqlClient;
using System.Net;
using System.Text;

class LoginServer
{
    static void Main(String[] args)
    {
        var listener = new HttpListener();
        var connector = new MySqlConnection("Server=localhost;Port=3306;Database=sunnight;Uid=root;Pwd=1234");
        listener.Prefixes.Add("http://localhost:3333/");

        while (true)
        {
            listener.Start();
            var context = listener.GetContext();

            if (context.Request.RawUrl == "/login")
            {
                using (var stream = new StreamReader(context.Request.InputStream, context.Request.ContentEncoding))
                {
                    var success = CheckLogin("", "");
                    if (success)
                    {
                        string responseString = "true";
                        byte[] buffer = Encoding.UTF8.GetBytes(responseString);
                        context.Response.ContentLength64 = buffer.Length;
                        Stream output = context.Response.OutputStream;
                        output.Write(buffer, 0, buffer.Length);

                        output.Close();
                        listener.Stop();
                    }
                    else
                    {

                    }
                }
            }
        }

        bool CheckLogin(string name, string pw)
        {
            using (MySqlConnection connection = connector)
            {
                try
                {
                    connection.Open();
                    string sql = "SELECT * FROM player";

                    MySqlCommand cmd = new MySqlCommand(sql, connection);
                    MySqlDataReader table = cmd.ExecuteReader();

                    while (table.Read())
                    {
                        //Console.WriteLine((string)table["player_name"], table["password"]);
                        string? playerName = table["player_name"].ToString();
                        // 인덱스를 사용하여 데이터 접근
                        string password = table.GetString(table.GetOrdinal("password"));
                        Console.WriteLine($"Player: {playerName}, Password: {password}");
                    }

                    connection.Close();
                }
                catch (Exception ex)
                {
                    Console.WriteLine(ex.ToString());
                }
            }
            return true;
        }
    }

}