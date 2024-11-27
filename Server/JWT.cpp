#include "pch.h"
#include <jwt-cpp/jwt.h>

static bool ValidateJwtToken(const string& token, const string& secretKey, const string& tokenType)
{
	try {
		auto decoded = jwt::decode(token);
		
		auto verifier = jwt::verify()
			.allow_algorithm(jwt::algorithm::hs256{ secretKey })
			.with_claim("username", jwt::claim(string("exampleUser")));

		verifier.verify(decoded);

		auto exp_claim = decoded.get_expires_at();
		auto now = chrono::system_clock::now();

		if (now > exp_claim) {
			cout << tokenType << "expired!" << endl;
			return false;
		}

		cout << tokenType << "validation successful!" << endl;
		return true;
	}
	catch (exception e) {
		cout << tokenType << "validation failed: " << e.what() << endl;
		return false;
	}
}

static string GenerateJwtToken(const string& username, const string& secretKey, chrono::minutes validity) 
{
	auto token = jwt::create()
		.set_issuer("auto_server")
		.set_type("JWT")
		.set_issued_at(chrono::system_clock::now())
		.set_expires_at(chrono::system_clock::now() + validity)
		.set_payload_claim("username", jwt::claim(username))
		.sign(jwt::algorithm::hs256{ secretKey });

	return token;
}

static void HandleToken(const string& accessToken, const string& refreshToken, const string& secretKey)
{
	bool isAccessTokenValid = ValidateJwtToken(accessToken, secretKey, "Access Token");
	bool isRefreshTokenValid = ValidateJwtToken(refreshToken, secretKey, "Refresh Token");

	if (isAccessTokenValid) 
	{
		cout << "Access Token is valid. Proceed with the request." << endl;
	}
	else if (isRefreshTokenValid) 
	{
		cout << "Access Token expired. Generating a new Access Token using Refresh Token..." << endl;
		string newAccessToken = GenerateJwtToken("exampleUser", secretKey, chrono::minutes(15));
		cout << "New Access Token: " << newAccessToken << endl;
	}
	else 
	{
		// Send login response to Client
		cout << "Both tokens are invalid. Re-login is required." << endl;
	}
}