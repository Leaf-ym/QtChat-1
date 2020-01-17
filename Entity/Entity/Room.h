#pragma once
#include "Entity.h"
struct ENTITY_EXPORT Room
{

	int id;
	QString name;

	QString password;
	
	QString comment;
	User host;

};

