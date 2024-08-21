#include "pch.h"
#include "Room.h"
#include "Player.h"
#include "GameSession.h"

RoomRef GRoom = make_shared<Room>();

Room::Room()
{

}

Room::~Room()
{

}

bool Room::HandleEnterPlayer(PlayerRef player)
{
	bool success = EnterPlayer(player);

	// ���� ��ġ
	player->playerInfo->set_posx(Utils::GetRandom(0.f, 500.f));
	player->playerInfo->set_posy(Utils::GetRandom(0.f, 500.f));

	// ���� ����� ���� �÷��̾�� �˸���
	{
		Protocol::S_ENTER_GAME enterGamePkt;
		enterGamePkt.set_success(success);

		Protocol::PlayerInfo* playerInfo = new Protocol::PlayerInfo();
		playerInfo->CopyFrom(*player->playerInfo);
		enterGamePkt.set_allocated_player(playerInfo);
		//enterGamePkt.release_player();

		SendBufferRef sendBuffer = ServerPacketHandler::MakeSendBuffer(enterGamePkt, Protocol::PKT_S_ENTER_GAME);
		if (auto session = player->session.lock())
			session->Send(sendBuffer);
	}

	// ���� ����� �ٸ� �÷��̾�� �˸��� 
	// -> �÷��̾ �� ���̸� ���� �˸��� �ʴ´�
	{
		Protocol::S_SPAWN spawnPkt;

		Protocol::PlayerInfo* playerInfo = spawnPkt.add_players();
		playerInfo->CopyFrom(*player->playerInfo);

		SendBufferRef sendBuffer = ServerPacketHandler::MakeSendBuffer(spawnPkt, Protocol::PKT_S_SPAWN);
		BroadCast(sendBuffer, player->playerInfo->playerid());
	}

	// ���� ������ �÷��̾� ����� ���� �÷��̾����� �������ش�
	cout << player->playerInfo->playerid() << " - Client Connected!" << endl;

	return success;
}

bool Room::HandleLeavePlayer(PlayerRef player)
{
	if (player == nullptr)
		return false;

	const uint64 objectId = player->playerInfo->playerid();
	bool success = LeavePlayer(objectId);

	// ���� ����� �����ϴ� �÷��̾�� �˸���
	{
		Protocol::S_LEAVE_GAME leaveGamePkt;

		SendBufferRef sendBuffer = ServerPacketHandler::MakeSendBuffer(leaveGamePkt, Protocol::PKT_S_LEAVE_GAME);
		if (auto session = player->session.lock())
			session->Send(sendBuffer);
	}

	// ���� ����� �˸���
	{
		Protocol::S_DESPAWN despawnPkt;
		despawnPkt.add_playerids(objectId);

		SendBufferRef sendBuffer = ServerPacketHandler::MakeSendBuffer(despawnPkt, Protocol::PKT_S_DESPAWN);
		BroadCast(sendBuffer, objectId);

		if (auto session = player->session.lock())
			session->Send(sendBuffer);
	}

	cout << player->playerInfo->playerid() << " - Client Disconnected!" << endl;
}

void Room::HandleMove(Protocol::C_MOVE& pkt)
{
	const uint64 objectId = pkt.playerinfo().playerid();
	if (_players.find(objectId) == _players.end())
		return;

	// ����
	PlayerRef& player = _players[objectId];
	player->playerInfo->CopyFrom(pkt.playerinfo());

	// �̵�
	{
		Protocol::S_MOVE movePkt;
		{
			Protocol::PlayerInfo* info = movePkt.mutable_playerinfo();
			info->CopyFrom(pkt.playerinfo());
		}

		SendBufferRef sendBuffer = ServerPacketHandler::MakeSendBuffer(movePkt, Protocol::PKT_S_MOVE);
		BroadCast(sendBuffer);
	}
}

void Room::HandleChat(Protocol::C_CHAT& pkt)
{
	cout << "input : " << pkt.msg() << endl;

	{
		Protocol::S_CHAT chatPkt;
		{
			chatPkt.set_msg(pkt.msg());
		}

		SendBufferRef sendBuffer = ServerPacketHandler::MakeSendBuffer(chatPkt, Protocol::PKT_S_CHAT);
		BroadCast(sendBuffer);
	}
}

bool Room::EnterPlayer(PlayerRef player)
{
	// �̹� �ִٸ� ������ �ִ�.
	if (_players.find(player->playerInfo->playerid()) != _players.end())
		return false;

	_players.insert(make_pair(player->playerInfo->playerid(), player));

	player->room.store(GRoom);

	return true;
}

bool Room::LeavePlayer(uint64 objectId)
{
	// ���ٸ� ������ �ִ�
	if (_players.find(objectId) == _players.end())
		return false;

	PlayerRef player = _players[objectId];
	player->room.store(weak_ptr<Room>());

	_players.erase(objectId);

	return true;
}

void Room::BroadCast(SendBufferRef sendBuffer, uint64 exceptId)
{
	for (auto& item : _players)
	{
		PlayerRef player = item.second;
		if (player->playerInfo->playerid() == exceptId)
			continue;

		if (GameSessionRef session = player->session.lock())
			session->Send(sendBuffer);
	}
}
