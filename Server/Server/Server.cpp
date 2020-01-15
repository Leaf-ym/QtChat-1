#include "Server.h"
#include "NetWorkHandler/NetWorkHandler.h"
#include "NetWorkHandler/ServerRegist.h"


Server::Server(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	server = new QTcpServer(this);

	connect(server, SIGNAL(newConnection()), this, SLOT(connectSlot()));
}


void Server::startClicked()
{
	if (server->isListening()) {
		ui.textEdit->append("started");
		return; 
	}
	if (server->listen(QHostAddress(HostIp), 12345)) {
		ui.textEdit->append("success");
	}
	else {
		ui.textEdit->append("fail");
	}
}

void Server::connectSlot()
{
	QTcpSocket* clientSocket = this->server->nextPendingConnection();
	new ServerRegist (clientSocket,this);
	ui.textEdit->append("connect");
}
