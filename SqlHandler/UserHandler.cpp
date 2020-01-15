#include "UserHandler.h"
#include <QVariant>
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
