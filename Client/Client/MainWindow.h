#pragma once

#include <QWidget>
#include "ui_MainWindow.h"
#include <QTcpSocket>
class MainWindow : public QWidget
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);
	~MainWindow();

private:
	Ui::MainWindow ui;
	QTcpSocket *client;

};
