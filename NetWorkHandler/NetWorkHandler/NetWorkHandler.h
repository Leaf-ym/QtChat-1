#pragma once

#include "networkhandler_global.h"
#include <QJsonObject>
#include <QJsonDocument>

#define HostIp "192.168.20.129"
#define Port 12345
#define MainPort 11111

//�Զ���Э���
class NETWORKHANDLER_EXPORT NetWorkHandler
{
public:
	enum dateType {
		none,               //��   0
		regist,             //ע��
		login,              //��¼
		offline,			//����
		online,				//����
		//chat               //����
		createroom,			//����Ⱥ��


		success = 100,
		fail
	};
	
public:
	NetWorkHandler(dateType type = NetWorkHandler::none);

	NetWorkHandler::dateType getType() const { return type; }
	void setType(NetWorkHandler::dateType val) { type = val; }

	QJsonValue operator[](const QString &key) const
	{
		return body[key];
	}
	QJsonValueRef operator[](const QString &key)
	{
		return body[key];
	}

	QByteArray pack();	//���
	int unpack(QByteArray byte);	//���
private:
	dateType    type;          //��ͷ
	QJsonObject body;          //����         ��ֵ��
};
