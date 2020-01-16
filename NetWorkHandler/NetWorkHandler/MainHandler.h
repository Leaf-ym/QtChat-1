#pragma once

#include <QTcpSocket>
#include "NetWorkHandler.h"
#include "networkhandler_global.h"
//产品接口
class NETWORKHANDLER_EXPORT MainHandler
{
public:
	MainHandler();
	~MainHandler();
	virtual void handler(QTcpSocket* clientSocket,
		const NetWorkHandler& pack) = 0;     //处理数据包
};
