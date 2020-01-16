#include "Server.h"
#include "NetWorkHandler/NetWorkHandler.h"
#include "NetWorkHandler/ServerRegist.h"


Server::Server(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	server = new QTcpServer(this);

	connect(server, SIGNAL(newConnection()), this, SLOT(connectSlot()));

	mainServer = new QTcpServer(this);
	connect(mainServer, SIGNAL(newConnection()), this, SLOT(mainSlot()));
}


void Server::startClicked()
{
	while (1)
	{
		if (server->isListening()) {
			ui.textEdit->append("login started");
			return;
		}
		if (server->listen(QHostAddress(HostIp), Port)) {
			ui.textEdit->append("login success");
		}
		else {
			ui.textEdit->append("login fail");
		}
	}
	while (1)
	{
		if (mainServer->isListening()) {
			ui.textEdit->append("main started");
			return;
		}
		if (mainServer->listen(QHostAddress(HostIp), Port)) {
			ui.textEdit->append("main success");
		}
		else {
			ui.textEdit->append("main fail");
		}
	}

}

void Server::connectSlot()
{
	QTcpSocket* clientSocket = this->server->nextPendingConnection();
	new ServerRegist (clientSocket,this);
}

void Server::mainSlot()
{

}
