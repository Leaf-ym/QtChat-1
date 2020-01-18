#include "MainWindow.h"
#include <QDebug>
#include <QHostAddress>
#include <QByteArray>
#include <QDataStream>
#include <QJsonDocument>
#include <QJsonArray>
#include <QListWidgetItem>

MainWindow::MainWindow(QWidget *parent)
	: QWidget(parent)
{
	client = new QTcpSocket(this);
	client->connectToHost(QHostAddress(HostIp), MainPort);

	loginWrite();
	connect(client, SIGNAL(readyRead()), this, SLOT(readSlot()));
	connect(ui.createroomButton, SIGNAL(clicked()), this, SLOT(createRoomWrite()));
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
}

void MainWindow::setName(const QString & userName)
{
	name = userName;
	ui.nameLabel->setText(name);
}

void MainWindow::readSlot()
{
	QByteArray byteArray = client->readAll();
	NetWorkHandler packRet;
	int len = 0;
	while (len = packRet.unpack(byteArray) > 0) 
	{
		switch (packRet.getType())
		{
		case NetWorkHandler::online:
			loginRead(packRet);
			break;
		case NetWorkHandler::createroom:
			createRoomRead(packRet);
			break;
		default:
			break;
		}
		byteArray = byteArray.mid(len);
	}
}





void MainWindow::loginWrite()
{
	NetWorkHandler nh;
	//��¼ʱ����һ�������б��ѯ
	nh.setType(NetWorkHandler::online);
	nh["list"] = "chatRooms";
	client->write(nh.pack());
}

void MainWindow::createRoomWrite()
{

}

void MainWindow::loginRead(const NetWorkHandler &package)
{
	QString type = package["type"].toString();

	if (type == "chatRooms")
	{
		QJsonArray array = package["rooms"].toArray();
		for (auto ar : array)
		{
			Room room;
			room.name = ar.toObject().value("name").toString();
			chatRooms.push_back(room);
			//QLabel *label=new QLabel(room.name, 0);
			QListWidgetItem *item = new QListWidgetItem(room.name,ui.roomList);
			ui.roomList->addItem(item);
		}
	}
	else{}
}

void MainWindow::createRoomRead(const NetWorkHandler &)
{
}
