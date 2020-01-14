#pragma once

#include <QtWidgets/QWidget>
#include "ui_Login.h"
#include "registWindow.h"
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
};
