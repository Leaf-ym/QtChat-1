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

	//解包
	NetWorkHandler packRet;
	int len = 0;
	NetWorkHandler nh;
	while (len = packRet.unpack(byteArray) > 0) {
		User user;
		user.setName(packRet["name"].toString());
		user.setPassword(packRet["password"].toString());
		UserHandler uh;
		if (packRet.getType() == NetWorkHandler::regist)
		{
			if (packRet["type"] == NetWorkHandler::regist)
			{
				if (!uh.selectUser(user))
				{
					uh.insertUser(user);
					nh.setType(NetWorkHandler::success);
					break;
				}
				else
				{
					nh.setType(NetWorkHandler::fail);
					break;
				}
			}
			else
			{
				if (!uh.selectUser(user))
				{
					uh.insertUser(user);
					uh.onlineUser(user);
					nh.setType(NetWorkHandler::success);
					break;
				}
				else
				{
					nh.setType(NetWorkHandler::fail);
					break;
				}
			}
		}
		else
		{
			
			if (uh.selectUser(user,1))
			{
				if (uh.onlineUser(user))
				{
					nh.setType(NetWorkHandler::success);
					break;
				}	
			}
			else
			{
				nh.setType(NetWorkHandler::fail);
				break;
			}
		}
		
	}
	clientSocket->write(nh.pack());
}


void ServerRegist::handler(QTcpSocket * clientSocket, NetWorkHandler & pack)
{

}
