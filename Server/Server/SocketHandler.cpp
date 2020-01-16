#include "SocketHandler.h"
#include "MainFactory.h"
#include "NetWorkHandler/NetWorkHandler.h"
#include "NetWorkHandler/MainHandler.h"
SocketHandler::SocketHandler(QObject *parent)
	: QObject(parent)
{
}

SocketHandler::SocketHandler(QTcpSocket * client, QObject * parent)
	: clientSocket(client),QObject(parent)
{
	//readyRead信号----> 当套接字中有数据到达时触发
	connect(this->clientSocket, SIGNAL(readyRead()),
		this, SLOT(readyReadSlot()));
}

SocketHandler::~SocketHandler()
{
}
void SocketHandler::readyReadSlot()
{
	QByteArray byteArray = this->clientSocket->readAll();
	//解包
	NetWorkHandler packRet;
	int len = 0;
	while (len = packRet.unpack(byteArray) > 0) {
		//创建工厂来处理不同的数据包
		MainFactory fh;
		MainHandler *ih = fh.createHandler(packRet.getType());

		//执行产品的操作
		if (ih != nullptr) {
			ih->handler(this->clientSocket, packRet);
			delete ih;
		}
		byteArray = byteArray.mid(len);
	}
}
