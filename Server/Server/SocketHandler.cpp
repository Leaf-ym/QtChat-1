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
	//readyRead�ź�----> ���׽����������ݵ���ʱ����
	connect(this->clientSocket, SIGNAL(readyRead()),
		this, SLOT(readyReadSlot()));
}

SocketHandler::~SocketHandler()
{
}
void SocketHandler::readyReadSlot()
{
	QByteArray byteArray = this->clientSocket->readAll();
	//���
	NetWorkHandler packRet;
	int len = 0;
	while (len = packRet.unpack(byteArray) > 0) {
		//��������������ͬ�����ݰ�
		MainFactory fh;
		MainHandler *ih = fh.createHandler(packRet.getType());

		//ִ�в�Ʒ�Ĳ���
		if (ih != nullptr) {
			ih->handler(this->clientSocket, packRet);
			delete ih;
		}
		byteArray = byteArray.mid(len);
	}
}
