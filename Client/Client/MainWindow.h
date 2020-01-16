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
	void closeEvent(QCloseEvent *event);
	void setName(const QString& userName);
private:
	Ui::MainWindow ui;
	QTcpSocket *client;
	QString name;

};
