#pragma once

#include <QtWidgets/QWidget>
#include "ui_Server.h"
#include <QTcpServer>
#include <QTcpSocket>

class Server : public QWidget
{
	Q_OBJECT

public:
	Server(QWidget *parent = Q_NULLPTR);

private:
	Ui::ServerClass ui;
	QTcpServer *server;
	QTcpServer *mainServer;
public slots:
	void startClicked();
	void connectSlot();
	void mainSlot();
};
