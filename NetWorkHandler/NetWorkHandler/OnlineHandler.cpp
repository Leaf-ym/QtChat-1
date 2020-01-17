#include "OnlineHandler.h"
#include "ChatRoomHelper.h"
#include "Entity/Room.h"
#include <QDataStream>
#include <QByteArray>
#include <QIODevice>
#include <QJsonDocument>
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
		QByteArray barry;
		QDataStream stream(&barry, QIODevice::WriteOnly);
		stream << rooms;
		nh["rooms"] = QJsonDocument::fromJson(barry).array();
		clientSocket->write(nh.pack());
	}
	else
	{ }
}
