#include "NetWorkHandler.h"

NetWorkHandler::NetWorkHandler(dateType type)
	:type(type)
{
}

//************************************
// Method:    pack
// FullName:  NetWorkHandler::pack
// Access:    public 
// Returns:   QByteArray
// Qualifier: ���
//************************************
QByteArray NetWorkHandler::pack()	
{
	QByteArray head(8, 0);          //�����С  + ��ͷ

		//��QJsonObject����ת��ΪQByteArray
	QByteArray qBody = QJsonDocument(this->body).toJson();

	*((int*)head.data()) = qBody.size();   //json�ַ����Ĵ�С
	*(dateType*)(head.data() + 4) = type;      //���ݰ���ͷ

	return head + qBody;
}

//************************************
// Method:    unpack
// FullName:  NetWorkHandler::unpack
// Access:    public 
// Returns:   int
// Qualifier: ���
// Parameter: QByteArray byte
//************************************
int NetWorkHandler::unpack(QByteArray byte)	
{
	if (byte.size() < 8)     return 0;

	int len = *((int*)byte.data());                 //�����С
	type = *(dateType*)(byte.data() + 4);      //��ͷ

	//��������
	QByteArray byteBody = byte.mid(8);

	if (byteBody.size() != len) return 0;

	body = QJsonDocument::fromJson(byteBody).object();
	return 8 + len;
}