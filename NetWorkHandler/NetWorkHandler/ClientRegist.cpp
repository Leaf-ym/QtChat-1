#include "ClientRegist.h"

ClientRegist::ClientRegist()
{
	
}
ClientRegist::~ClientRegist()
{
}

void ClientRegist::run(NetWorkHandler &package)
{
	qDebug() << "write";
	clientSocket->write(package.pack());
}

