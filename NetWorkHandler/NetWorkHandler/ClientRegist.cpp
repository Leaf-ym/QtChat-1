#include "ClientRegist.h"
#include "NetWorkHandler.h"

ClientRegist::ClientRegist(const User & user, QTcpSocket *socket)
	:user(user), regist(socket)
{
}
ClientRegist::~ClientRegist()
{
}

void ClientRegist::run()
{
	NetWorkHandler package(NetWorkHandler::regist);
	package["name"] = user.getName();
	package["password"] = user.getPassword();
	regist->write(package.pack());
}