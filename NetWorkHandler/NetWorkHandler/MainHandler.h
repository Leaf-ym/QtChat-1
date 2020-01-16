#pragma once

#include <QTcpSocket>
#include "NetWorkHandler.h"

//产品接口
class MainHandler
{
public:
	MainHandler();
	~MainHandler();
	virtual void handler(QTcpSocket* clientSocket,
		const NetWorkHandler& pack) = 0;     //处理数据包
};
