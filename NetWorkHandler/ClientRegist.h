#pragma once

#include <QObject>
#include "Entity/User.h"
#include <QTcpSocket>
class ClientRegist
{
private:
	User user;
	QTcpSocket *regist;
public:
	ClientRegist(const User& user, QTcpSocket *client);
	~ClientRegist();

	void run();
};
