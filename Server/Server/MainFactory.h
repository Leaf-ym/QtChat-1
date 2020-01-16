#pragma once

#include "NetWorkHandler/MainHandler.h"
class MainFactory
{
public:
	MainFactory();
	~MainFactory();

	MainHandler* createHandler(NetWorkHandler::dateType type = NetWorkHandler::none);
};
