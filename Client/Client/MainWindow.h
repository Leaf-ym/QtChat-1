#pragma once

#include <QWidget>
#include "ui_MainWindow.h"
#include <QTcpSocket>
#include <QVector>
#include "ChatRoomWindow.h"
#include "NetWorkHandler/NetWorkHandler.h"
#include "Entity/Room.h"
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

	QVector<Room> chatRooms;//当前聊天房间的合集
public slots:
	void readSlot();

private:
	void loginRead(const NetWorkHandler&);



};
