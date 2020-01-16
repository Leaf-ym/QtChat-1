#include "MainFactory.h"

MainFactory::MainFactory()
{
}

MainFactory::~MainFactory()
{
}

MainHandler * MainFactory::createHandler(NetWorkHandler::dateType type)
{
	MainHandler* myHandler = nullptr;

	switch (type)
	{
	case NetWorkHandler::none:
		break;
	case NetWorkHandler::regist:
		break;
	case NetWorkHandler::login:
		break;
	case NetWorkHandler::success:
		break;
	case NetWorkHandler::fail:
		break;
	default:
		break;
	}

	return myHandler;
}
