#include "ClientLogin.h"

ClientLogin::~ClientLogin()
{
}

void ClientLogin::run(NetWorkHandler & pack)
{
	clientSocket->write(pack.pack());
}
