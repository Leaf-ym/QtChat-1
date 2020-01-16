#pragma once
#include <QMap>
#include <QTcpSocket>
#include <QMutex>
class CurrentUser
{
public:
	~CurrentUser();

	static CurrentUser *getInst();

	//����û�
	void insertNewClient(const QTcpSocket*);
	//�����û�
private:
	QMap<const QTcpSocket*, QString> users;
	CurrentUser();
	
	CurrentUser(const CurrentUser&) = delete;
	CurrentUser operator=(const CurrentUser&) = delete;
	static CurrentUser* instance;
	static QMutex mutex;
};
