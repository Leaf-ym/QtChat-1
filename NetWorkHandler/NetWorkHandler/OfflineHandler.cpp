#include "OfflineHandler.h"
#include "UserHandler.h"
#include "Entity/User.h"
#include <QDebug>
OfflineHandler::OfflineHandler()
{
}

OfflineHandler::~OfflineHandler()
{
}

void OfflineHandler::handler(QTcpSocket * clientSocket, const NetWorkHandler & pack)
{
	QString name = pack["name"].toString();
	User user;
	user.setName(name);
	UserHandler().offlineUser(user);
}
