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
// Qualifier: 封包
//************************************
QByteArray NetWorkHandler::pack()	
{
	QByteArray head(8, 0);          //包体大小  + 包头

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
// Qualifier: 解包
// Parameter: QByteArray byte
//************************************
int NetWorkHandler::unpack(QByteArray byte)	
{
	if (byte.size() < 8)     return 0;

	int len = *((int*)byte.data());                 //包体大小
	type = *(dateType*)(byte.data() + 4);      //包头

	//解析包体
	QByteArray byteBody = byte.mid(8);

	if (byteBody.size() != len) return 0;

	body = QJsonDocument::fromJson(byteBody).object();
	return 8 + len;
}