using System.Net;
using System.Text;

class Program
{
    static void Main(String[] args)
    {
        var listener = new HttpListener();
        listener.Prefixes.Add("http://localhost:3333/");
        listener.Start();

        while(true)
        {
            var context = listener.GetContext();

            if(context.Request.RawUrl == "/login")
            {
                using (var stream = new StreamReader(context.Request.InputStream, context.Request.ContentEncoding))
                {
                    var success = CheckLogin("","");
                    if(success)
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
    }

    static bool CheckLogin(string name, string pw)
    {
        return true;
    }
}