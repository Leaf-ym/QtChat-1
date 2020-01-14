#include "NetWorkHandler.h"

NetWorkHandler::NetWorkHandler(dateType type)
	:type(type)
{
}
//键值对的访问
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
// Qualifier:对自定义协议头进行封装
//************************************
QByteArray NetWorkHandler::pack()
{
	QByteArray head(sizeof(int)+sizeof(type), 0);          //包体大小  + 包头

		//将QJsonObject对象转化为QByteArray
	QByteArray qBody = QJsonDocument(this->body).toJson();

	*((int*)head.data()) = qBody.size();   //json字符串的大小
	*(dateType*)(head.data() + 4) = type;      //数据包的头

	return head + qBody;
}

//************************************
// Method:    unpack
// FullName:  NetWorkHandler::unpack
// Access:    public 
// Returns:   int
// Qualifier:对自定义协议头进行拆包
// Parameter: QByteArray byte
//************************************
int NetWorkHandler::unpack(QByteArray byte)
{
	if (byte.size() < 8)     return 0;

	int len = *((int*)byte.data());                 //包体大小
	this->type = *(dateType*)(byte.data() + 4);      //包头

	//解析包体
	QByteArray byteBody = byte.mid(8);

	if (byteBody.size() != len) return 0;

	this->body = QJsonDocument::fromJson(byteBody).object();
	return 8 + len;
}
