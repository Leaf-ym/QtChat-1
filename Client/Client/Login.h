#pragma once

#include <QtWidgets/QWidget>
#include "ui_Login.h"
#include "registWindow.h"
#include "MainWindow.h"
class Login : public QWidget
{
	Q_OBJECT

public:
	Login(QWidget *parent = Q_NULLPTR);

private:
	Ui::LoginClass ui;
	//registWindow *registWin;
public slots:
	void registClicked();
	void loginClicked();

public:
	void setName(const QString& name);

};
