#include "NetWorkHandler.h"

NetWorkHandler::NetWorkHandler(dateType type)
	:type(type)
{
}
//��ֵ�Եķ���
QJsonValue NetWorkHandler::operator[](const QString & key) const
{
	return body[key];
}
QJsonValueRef NetWorkHandler::operator[](const QString & key)
{
	return body[key];
}

//************************************
// Method:    pack
// FullName:  NetWorkHandler::pack
// Access:    public 
// Returns:   QT_NAMESPACE::QByteArray
// Qualifier:���Զ���Э��ͷ���з�װ
//************************************
QByteArray NetWorkHandler::pack()
{
	QByteArray head(sizeof(int)+sizeof(type), 0);          //�����С  + ��ͷ

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
// Qualifier:���Զ���Э��ͷ���в��
// Parameter: QByteArray byte
//************************************
int NetWorkHandler::unpack(QByteArray byte)
{
	if (byte.size() < 8)     return 0;

	int len = *((int*)byte.data());                 //�����С
	this->type = *(dateType*)(byte.data() + 4);      //��ͷ

	//��������
	QByteArray byteBody = byte.mid(8);

	if (byteBody.size() != len) return 0;

	this->body = QJsonDocument::fromJson(byteBody).object();
	return 8 + len;
}
