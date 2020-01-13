#pragma once
#include "entity_global.h"
#include <QString>
class User
{
private:
	int id;
	QString name;
	QString password;
	bool online;

public:
	User();
	~User();
	
	int getId() const { return id; }
	void setId(int val) { id = val; }

	QString getName() const { return name; }
	void setName(QString val) { name = val; }

	QString getPassword() const { return password; }
	void setPassword(QString val) { password = val; }

	bool getOnline() const { return online; }
	void setOnline(bool val) { online = val; }

};

