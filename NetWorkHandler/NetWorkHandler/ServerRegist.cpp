#include "ServerRegist.h"
#include "Entity/User.h"
#include "SqlHandler.h"
#include <QSqlQuery>
#include "UserHandler.h"
ServerRegist::ServerRegist(QObject *parent) : QObject(parent)
{
}
ServerRegist::ServerRegist(QTcpSocket* clientSocket,QObject *parent)
	: clientSocket(clientSocket),QObject(parent)
{
	//readyRead信号----> 当套接字中有数据到达时触发
	connect(clientSocket, SIGNAL(readyRead()),
		this, SLOT(readyReadSlot()));
}
ServerRegist::~ServerRegist()
{
}
void ServerRegist::readyReadSlot()
{
	QByteArray byteArray = this->clientSocket->readAll();

	qDebug() << "read";
	//解包
	NetWorkHandler packRet;
	int len = 0;
	NetWorkHandler nh;
	while (len = packRet.unpack(byteArray) > 0) {
		User user;
		user.setName(packRet["name"].toString());
		user.setPassword(packRet["password"].toString());
		UserHandler uh;
		if (!uh.selectUser(user))
		{
			uh.insertUser(user);
			nh.setType(NetWorkHandler::success);
			qDebug() << "successRegist";
			break;
		}
		else
		{
			nh.setType(NetWorkHandler::fail);
			qDebug() << "failRegist";
			break;
		}
	}
	clientSocket->write(nh.pack());
}


void ServerRegist::handler(QTcpSocket * clientSocket, NetWorkHandler & pack)
{

}
