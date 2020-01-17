#include "OnlineHandler.h"
#include "ChatRoomHelper.h"
#include "Entity/Room.h"
#include <QDataStream>
#include <QByteArray>
#include <QIODevice>
#include <QJsonDocument>
#include <QJsonArray>
OnlineHandler::OnlineHandler()
{
}

OnlineHandler::~OnlineHandler()
{
}

void OnlineHandler::handler(QTcpSocket * clientSocket, const NetWorkHandler & pack)
{
	QString name = pack["list"].toString();

	NetWorkHandler nh;
	nh.setType(NetWorkHandler::online);
	if (name == "chatRooms")
	{
		nh["type"] = name;
		ChatRoomHelper *ins = ChatRoomHelper::getInstance();
		QVector<Room> rooms = ins->selectAllRoom();
		QJsonArray array;
		int i = 0;
		for (auto room:rooms)
		{
			QJsonObject obj;
			obj.insert("name", room.name);
			array.insert(i,obj);
			++i;
		}
		nh["rooms"] = array;
		clientSocket->write(nh.pack());
	}
	else
	{ }
}
