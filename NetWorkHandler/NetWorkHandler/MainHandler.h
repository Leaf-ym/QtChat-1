#pragma once

#include <QTcpSocket>
#include "NetWorkHandler.h"
#include "networkhandler_global.h"
//��Ʒ�ӿ�
class NETWORKHANDLER_EXPORT MainHandler
{
public:
	MainHandler();
	~MainHandler();
	virtual void handler(QTcpSocket* clientSocket,
		const NetWorkHandler& pack) = 0;     //�������ݰ�
};
