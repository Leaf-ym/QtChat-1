#pragma once

#include <QWidget>
#include "ui_MainWindow.h"
#include <QTcpSocket>
#include <QVector>
#include "ChatRoomWindow.h"
class MainWindow : public QWidget
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);
	~MainWindow();
	void closeEvent(QCloseEvent *event);
	void setName(const QString& userName);

	void loginWrite();
private:
	Ui::MainWindow ui;

	QTcpSocket *client;
	QString name;

	QVector<ChatRoomWindow *> chatRooms;//当前打开聊天房间的合集

};
