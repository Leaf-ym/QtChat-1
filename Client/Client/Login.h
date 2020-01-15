#pragma once

#include <QtWidgets/QWidget>
#include "ui_Login.h"
#include "registWindow.h"
#include <QTcpSocket>
#include "MainWindow.h"
class Login : public QWidget
{
	Q_OBJECT

public:
	Login(QWidget *parent = Q_NULLPTR);

private:
	Ui::LoginClass ui;
	//registWindow *registWin;
	QTcpSocket *login;

public slots:
	void registClicked();
	void loginClicked();
	void loginSlot();

public:
	void setName(const QString& name);

};
