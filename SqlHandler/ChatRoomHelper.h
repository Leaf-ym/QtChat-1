#pragma once

#include <QVector>
#include "SqlHandler.h"
#include "Entity/Room.h"
#include "Entity/User.h"
#include <QMutex>

class SQLHANDLER_EXPORT ChatRoomHelper
{
private:
	ChatRoomHelper();
	~ChatRoomHelper();

	static ChatRoomHelper* instance;

	QVector<Room> rooms;
	static QMutex mutex;

public:
	static ChatRoomHelper *getInstance();

	void insertRoom(Room& room) { rooms.push_back(room); }
	QVector<Room> selectAllRoom() { return rooms; }
};

