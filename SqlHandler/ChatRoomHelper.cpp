#include "ChatRoomHelper.h"

QMutex ChatRoomHelper::mutex;
ChatRoomHelper* ChatRoomHelper::instance = nullptr;

ChatRoomHelper::ChatRoomHelper()
{
	Room room;
	room.name = "dfzz";
	rooms.push_back(room);
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




