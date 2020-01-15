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
	//��ֹ��������͸�ֵ����
	SqlHandler(const SqlHandler&) = delete;
	SqlHandler& operator = (const SqlHandler&) = delete;
	static SqlHandler* instance;
	static QMutex mutex;
public:
	static SqlHandler* getInstance();
	//�����ݿ�
	bool createConnection();
	//�ر����ݿ�
	void removeConnection();

};
