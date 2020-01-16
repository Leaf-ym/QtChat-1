#pragma once
#include <QMap>
#include <QTcpSocket>
#include <QMutex>
class CurrentUser
{
public:
	~CurrentUser();

	static CurrentUser *getInst();

	//添加用户
	void insertNewClient(const QTcpSocket*);
	//查找用户
private:
	QMap<const QTcpSocket*, QString> users;
	CurrentUser();
	
	CurrentUser(const CurrentUser&) = delete;
	CurrentUser operator=(const CurrentUser&) = delete;
	static CurrentUser* instance;
	static QMutex mutex;
};
