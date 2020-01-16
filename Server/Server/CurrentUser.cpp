#include "CurrentUser.h"

CurrentUser::CurrentUser()
{
}

CurrentUser::~CurrentUser()
{
}

QMutex CurrentUser::mutex;
CurrentUser* CurrentUser::instance = nullptr;

//µ¥Àý
CurrentUser * CurrentUser::getInst()
{
	if (nullptr == instance) {
		mutex.lock();
		if (nullptr == instance)
			instance = new CurrentUser();
		mutex.unlock();
	}
	return instance;
}

void CurrentUser::insertNewClient(const QTcpSocket *client)
{
	users.insert(client, QString());
}
