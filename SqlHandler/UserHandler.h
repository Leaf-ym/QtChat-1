#pragma once
#include "SqlHandler.h"
#include "QSqlQuery"
#include "sqlhandler_global.h"
class SQLHANDLER_EXPORT UserHandler
{
public:
	UserHandler();
	~UserHandler();

	bool selectUser(const User& user);
	bool selectUser(const User& user, const int flag);
	void insertUser(const User& user);
	bool offlineUser(const User& user);
	bool onlineUser(const User& user);
};
