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

	//添加用户
	void insertNewClient(const SocketHandler*);
	//查找用户
private:
	QVector<const SocketHandler*> users;
	CurrentUser();
	
	CurrentUser(const CurrentUser&) = delete;
	CurrentUser operator=(const CurrentUser&) = delete;
	static CurrentUser* instance;
	static QMutex mutex;
};
