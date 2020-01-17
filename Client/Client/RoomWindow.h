#pragma once

#include <QWidget>
#include "ui_RoomWindow.h"

class RoomWindow : public QWidget
{
	Q_OBJECT

public:
	RoomWindow(QWidget *parent = Q_NULLPTR);
	~RoomWindow();

private:
	Ui::RoomWindow ui;
};
