#pragma once

#include <QObject>
#include <QTcpSocket>
class SocketHandler : public QObject
{
	Q_OBJECT

public:
	SocketHandler(QObject *parent=0);
	SocketHandler(QTcpSocket* clientSoket, QObject *parent = 0);
	~SocketHandler();

public slots:
	void readyReadSlot();

private:
	QTcpSocket* clientSocket;
};
