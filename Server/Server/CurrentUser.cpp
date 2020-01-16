#include "CurrentUser.h"

CurrentUser::CurrentUser()
{
}

CurrentUser::~CurrentUser()
{
}

QMutex CurrentUser::mutex;
CurrentUser* CurrentUser::instance = nullptr;

//µ¥Àı
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

void CurrentUser::insertNewClient(const SocketHandler *client)
{
	users.push_back(client);
}
