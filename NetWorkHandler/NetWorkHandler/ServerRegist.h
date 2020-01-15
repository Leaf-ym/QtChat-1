#pragma once
#include "networkhandler_global.h"
#include "NetWorkHandler.h"
#include <QTcpSocket>
class NETWORKHANDLER_EXPORT ServerRegist : public QObject
{
	Q_OBJECT

public:
	ServerRegist(QObject *parent = 0);
	ServerRegist(QTcpSocket* clientSoket, QObject *parent = 0);
	~ServerRegist();
	void handler(QTcpSocket* clientSocket, NetWorkHandler &pack);
private:
	QTcpSocket* clientSocket;

public slots:
	void readyReadSlot();
};
