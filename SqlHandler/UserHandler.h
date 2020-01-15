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
	void insertUser(const User& user);
};
