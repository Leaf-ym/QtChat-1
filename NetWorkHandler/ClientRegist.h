#pragma once

#include <QObject>
#include "Entity/User.h"
#include <QTcpSocket>
class ClientRegist
{
private:
	User user;
public:
	ClientRegist(const User& user);
	~ClientRegist();

	void run();
};
