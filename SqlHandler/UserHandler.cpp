#include "UserHandler.h"
#include <QVariant>
#include <QDebug>
UserHandler::UserHandler()
{
}

UserHandler::~UserHandler()
{
}

bool UserHandler::selectUser(const User & user)
{
	SqlHandler *ins = SqlHandler::getInstance();
	ins->createConnection();

	QSqlQuery query;
	query.prepare("select name from user where name = :name");
	query.bindValue(":name", user.getName());
	query.exec();
	return query.next();
}

bool UserHandler::selectUser(const User & user, const int flag)
{
	SqlHandler *ins = SqlHandler::getInstance();
	ins->createConnection();

	QSqlQuery query;
	query.prepare("select name from user where name = :name and password=:pwd");
	query.bindValue(":name", user.getName());
	query.bindValue(":pwd", user.getPassword().toInt());
	query.exec();
	return query.next();
}

void UserHandler::insertUser(const User & user)
{
	SqlHandler *ins = SqlHandler::getInstance();
	ins->createConnection();

	QSqlQuery query;
	query.prepare("insert into user(name, password) values(:name, :pwd)");
	query.bindValue(":name", user.getName());
	query.bindValue(":pwd", user.getPassword());
	query.exec();
}

bool UserHandler::offlineUser(const User & user)
{
	SqlHandler *ins = SqlHandler::getInstance();
	ins->createConnection();

	QSqlQuery query;
	query.prepare("select online from user where name = :name");
	query.bindValue(":name", user.getName());
	query.exec();
	if (query.next())
	{
		if (query.value("online") == 0)return false;
	}
	else
	{
		return false;
	}
		
	query.prepare("update user set online = 0 where name = :name");
	query.bindValue(":name", user.getName());
	query.exec();
	
	return true;
}

bool UserHandler::onlineUser(const User & user)
{
	SqlHandler *ins = SqlHandler::getInstance();
	ins->createConnection();

	QSqlQuery query;
	query.prepare("select online from user where name = :name");
	query.bindValue(":name", user.getName());
	query.exec();
	if (query.next())
	{
		if (query.value("online") == 1)return false;
	}
	else
	{
		return false;
	}

	query.prepare("update user set online = 1 where name = :name");
	query.bindValue(":name", user.getName());
	query.exec();

	return true;
}
