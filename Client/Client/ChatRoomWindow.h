#pragma once

#include <QWidget>
#include "ui_ChatRoomWindow.h"

class ChatRoomWindow : public QWidget
{
	Q_OBJECT

public:
	ChatRoomWindow(QWidget *parent = Q_NULLPTR);
	~ChatRoomWindow();

private:
	Ui::ChatRoomWindow ui;
};
