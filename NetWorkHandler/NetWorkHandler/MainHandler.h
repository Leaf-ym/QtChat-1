#pragma once

#include <QTcpSocket>
#include "NetWorkHandler.h"

//��Ʒ�ӿ�
class MainHandler
{
public:
	MainHandler();
	~MainHandler();
	virtual void handler(QTcpSocket* clientSocket,
		const NetWorkHandler& pack) = 0;     //�������ݰ�
};
