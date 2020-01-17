#include "MainFactory.h"
#include "NetWorkHandler/OfflineHandler.h"
#include "NetWorkHandler/OnlineHandler.h"
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
	case NetWorkHandler::offline:
		myHandler = new OfflineHandler();
		break;
	case NetWorkHandler::online:
		myHandler = new OnlineHandler();
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
