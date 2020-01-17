#include "ChatRoomHelper.h"

QMutex SqlHandler::mutex;
ChatRoomHelper* ChatRoomHelper::instance = nullptr;

ChatRoomHelper::ChatRoomHelper()
{
}


ChatRoomHelper::~ChatRoomHelper()
{
}

ChatRoomHelper * ChatRoomHelper::getInstance()
{
	if (nullptr == instance) {
		mutex.lock();
		if (nullptr == instance) {
			instance = new ChatRoomHelper();
		}
		mutex.unlock();
	}
	return instance;
}




