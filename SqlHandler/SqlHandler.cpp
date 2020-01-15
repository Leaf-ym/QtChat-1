#include "SqlHandler.h"
#include <QDebug>
#include <QSqlError>
SqlHandler* SqlHandler::instance = 0;
QMutex SqlHandler::mutex;

SqlHandler::SqlHandler()
{
	db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("127.0.0.1");
	db.setPort(3306);
	db.setUserName("dfzz");
	db.setPassword("Ww132134");
}

SqlHandler * SqlHandler::getInstance()
{

	if (nullptr == instance) {
		mutex.lock();
		if (nullptr == instance) {
			instance = new SqlHandler();
		}
		mutex.unlock();
	}
	return instance;
}

bool SqlHandler::createConnection()
{
	db.setDatabaseName("qtchat");
	if (!db.open()) {
		qDebug() << db.lastError().text();
		return false;
	}
	return true;
}

void SqlHandler::removeConnection()
{
	db.close();
	db.removeDatabase("fruit");
}

