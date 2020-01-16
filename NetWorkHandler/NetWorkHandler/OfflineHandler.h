#pragma once

#include "MainHandler.h"
#include "networkhandler_global.h"
class NETWORKHANDLER_EXPORT OfflineHandler : public MainHandler
{

public:
	OfflineHandler();
	~OfflineHandler();
	void handler(QTcpSocket* clientSocket, const NetWorkHandler& pack);
};
