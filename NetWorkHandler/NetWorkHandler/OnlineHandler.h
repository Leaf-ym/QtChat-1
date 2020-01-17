#pragma once

#include "MainHandler.h"

class NETWORKHANDLER_EXPORT OnlineHandler : public MainHandler
{
public:
	OnlineHandler();
	~OnlineHandler();
	void handler(QTcpSocket* clientSocket, const NetWorkHandler& pack);
};
