#include "MainWindow.h"
#include "NetWorkHandler/NetWorkHandler.h"
#include <QDebug>
#include <QHostAddress>
MainWindow::MainWindow(QWidget *parent)
	: QWidget(parent)
{
	client = new QTcpSocket(this);
	client->connectToHost(QHostAddress(HostIp), MainPort);

	loginWrite();
	ui.setupUi(this);
}

MainWindow::~MainWindow()
{
}

void MainWindow::closeEvent(QCloseEvent * event)
{
	NetWorkHandler nh;
	nh.setType(NetWorkHandler::offline);
	nh["name"] = name;
	client->write(nh.pack());
	//client->readAll();
	//delete client;
}

void MainWindow::setName(const QString & userName)
{
	name = userName;
	ui.nameLabel->setText(name);
}

void MainWindow::loginWrite()
{
	NetWorkHandler nh;
	//��¼ʱ����һ�������б��ѯ
	nh.setType(NetWorkHandler::online);
	nh["list"] = "chatRooms";
	client->write(nh.pack());
}

