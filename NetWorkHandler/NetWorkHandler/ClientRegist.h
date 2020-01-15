#pragma once

#include <QObject>
#include "Entity/User.h"
#include <QTcpSocket>
#include "networkhandler_global.h"
#include "NetWorkHandler.h"
class NETWORKHANDLER_EXPORT ClientRegist :public QObject
{
	Q_OBJECT
private:
	QTcpSocket* clientSocket;
public:
	ClientRegist();
	ClientRegist(QTcpSocket* clientSocket, QObject *parent=0)
		: clientSocket(clientSocket), QObject(parent) 
	{
	};
	~ClientRegist();

	void run( NetWorkHandler &pack);
	//void handler(const NetWorkHandler &pack);

};