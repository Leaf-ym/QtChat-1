#pragma once

#include <QObject>
#include "Entity/User.h"
#include <QTcpSocket>
#include "networkhandler_global.h"
class NETWORKHANDLER_EXPORT ClientRegist
{
private:
	User user;
	QTcpSocket *regist;
public:
	ClientRegist(const User& user, QTcpSocket *client);
	~ClientRegist();

	void run();
};