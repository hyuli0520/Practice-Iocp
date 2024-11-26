using Microsoft.IdentityModel.Tokens;
using MySql.Data.MySqlClient;
using System.IdentityModel.Tokens.Jwt;
using System.Net;
using System.Security.Claims;
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
                    string? line;
                    bool success = false;
                    string? accessToken = null;
                    string? refreshToken = null;
                    string secretKey = "MyVeryLongAndSecureSecretKey12345";
                    while ((line = stream.ReadLine()) != null)
                    {
                        string[] str = line.Split('&');
                        string username = str[0];
                        string password = str[1];
                        success = CheckLogin(username, password);
                    
                        if(success)
                        {
                            accessToken = GenerateJwtToken(username, secretKey, TimeSpan.FromMinutes(15));
                            refreshToken = GenerateJwtToken(username, secretKey, TimeSpan.FromDays(7));
                        }
                    }

                    // Response: Access Token과 Refresh Token을 JSON 형식으로 반환
                    string responseString = success
                        ? $"{{\"accessToken\": \"{accessToken}\", \"refreshToken\": \"{refreshToken}\"}}"
                        : "fail";

                    byte[] buffer = Encoding.UTF8.GetBytes(responseString);
                    context.Response.ContentLength64 = buffer.Length;
                    Stream output = context.Response.OutputStream;
                    output.Write(buffer, 0, buffer.Length);

                    output.Close();
                    listener.Stop();
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
                        if (name == playerName)
                        {
                            if (pw == password)
                            {
                                Console.WriteLine("success to login");
                                return true;
                            }
                        }
                    }
                }
                catch (Exception ex)
                {
                    Console.WriteLine(ex.ToString());
                    return false;
                }
            }
            return true;
        }
    }

    static string GenerateJwtToken(string username, string secretKey, TimeSpan tokenValidity)
    {
        var tokenHandler = new JwtSecurityTokenHandler();
        var key = Encoding.UTF8.GetBytes(secretKey);

        var tokenDescriptor = new SecurityTokenDescriptor
        {
            Subject = new ClaimsIdentity(new[] { new Claim("username", username) }),
            Expires = DateTime.UtcNow.Add(tokenValidity), // 토큰 만료 시간
            SigningCredentials = new SigningCredentials(new SymmetricSecurityKey(key), SecurityAlgorithms.HmacSha256Signature)
        };

        var token = tokenHandler.CreateToken(tokenDescriptor);
        return tokenHandler.WriteToken(token);
    }
}