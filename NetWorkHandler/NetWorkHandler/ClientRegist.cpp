#include "ClientRegist.h"

ClientRegist::ClientRegist()
{
	
}
ClientRegist::~ClientRegist()
{
}

void ClientRegist::run(NetWorkHandler &package)
{
	clientSocket->write(package.pack());
}

