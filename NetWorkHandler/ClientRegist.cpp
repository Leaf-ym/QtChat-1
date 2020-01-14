#include "ClientRegist.h"
#include "NetWorkHandler.h"

ClientRegist::ClientRegist(const User& user)
	:user(user)
{
}

ClientRegist::~ClientRegist()
{
}
/*
void ClientRegist::run()
{
	//QTcpSocket *regist;
	NetWorkHandler pack(NetWorkHandler::regist);
	pack["name"] = user.getName();
	pack["password"] = user.getPassword();
	//regist->write(pack.pack());
}
*/
void ClientRegist::run()
{}