#pragma once

#include "sqlhandler_global.h"
#include "Entity/User.h"
#include <QSqlDatabase>
#include <QMutex>
class SQLHANDLER_EXPORT SqlHandler
{
private:
	QSqlDatabase db;
	SqlHandler();
	//禁止拷贝构造和赋值操作
	SqlHandler(const SqlHandler&) = delete;
	SqlHandler& operator = (const SqlHandler&) = delete;
	static SqlHandler* instance;
	static QMutex mutex;
public:
	static SqlHandler* getInstance();
	//打开数据库
	bool createConnection();
	//关闭数据库
	void removeConnection();

};
