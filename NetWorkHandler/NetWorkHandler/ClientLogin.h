#pragma once

#include <QObject>
#include <QTcpSocket>
#include "networkhandler_global.h"
#include "NetWorkHandler.h"
class NETWORKHANDLER_EXPORT ClientLogin : public QObject
{
	Q_OBJECT

private:
	QTcpSocket* clientSocket;
public:
	ClientLogin(QTcpSocket* clientSocket, QObject *parent = 0)
		: clientSocket(clientSocket), QObject(parent)
	{
	}
	~ClientLogin();
	void run(NetWorkHandler &pack);
};
