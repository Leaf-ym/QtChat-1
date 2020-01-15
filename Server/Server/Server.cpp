#include "Server.h"
#include "NetWorkHandler/NetWorkHandler.h"
Server::Server(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	server = new QTcpServer(this);
}


void Server::startClicked()
{
	if (server->isListening()) {
		ui.textEdit->append("start");
		return;
	}
	if (server->listen(QHostAddress(HostIp), 12345)) {
		ui.textEdit->append("success");
	}
	else {
		ui.textEdit->append("fail");
	}
}