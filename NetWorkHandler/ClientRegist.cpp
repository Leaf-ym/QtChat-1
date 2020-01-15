#include "ClientRegist.h"
#include "NetWorkHandler.h"

ClientRegist::ClientRegist(const User & user, QTcpSocket *socket)
	:user(user),regist(socket)
{
}

ClientRegist::~ClientRegist()
{
}

void ClientRegist::run()
{
	NetWorkHandler pack(NetWorkHandler::regist);
	pack["name"] = user.getName();
	pack["password"] = user.getPassword();
	regist->write(pack.pack());
}
