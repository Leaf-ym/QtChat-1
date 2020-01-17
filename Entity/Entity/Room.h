#pragma once
#include <QDataStream>
#include "entity_global.h"
template<class T>
T get(QDataStream &stream) {
	T value;
	stream >> value;
	return value;
}
class ENTITY_EXPORT Room
{
public:
	int id;
	QString name;

	QString password;
	
	QString comment;
	//User host;

	friend QDataStream & operator << (QDataStream &stream, const Room &room)
	{
		stream << (int)room.id << (QString)room.name << (QString)room.password
			<< (QString)room.comment;
		return stream;
	}
	friend QDataStream & operator >> (QDataStream &stream, Room &room)
	{
		room.id = get<int>(stream);
		room.name = get<QString>(stream);
		room.password = get<QString>(stream);
		room.comment = get<QString>(stream);
		return stream;
	}
	~Room();

};
