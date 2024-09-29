#pragma once

/*-----------------
	LoginSession
-----------------*/

class LoginSession : public PacketSession
{
public:
	~LoginSession() { }

	virtual void OnConnected() override;
	virtual void OnDisconnected() override;
	virtual void OnRecvPacket(BYTE* buffer, int32 len) override;
	virtual void OnSend(int32 len) override;

	string GetName() { return _name; }

	void Response();
private:
	string _id, _pw, _name;
};

