#pragma once
#include <QTcpSocket>
#include <QMutex>
#include <QVector>
#include "SocketHandler.h"
class CurrentUser
{
public:
	~CurrentUser();

	static CurrentUser *getInst();

	//����û�
	void insertNewClient(const SocketHandler*);
	//�����û�
private:
	QVector<const SocketHandler*> users;
	CurrentUser();
	
	CurrentUser(const CurrentUser&) = delete;
	CurrentUser operator=(const CurrentUser&) = delete;
	static CurrentUser* instance;
	static QMutex mutex;
};
