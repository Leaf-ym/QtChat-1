#pragma once

#include <QtWidgets/QWidget>
#include "ui_Login.h"

class Login : public QWidget
{
	Q_OBJECT

public:
	Login(QWidget *parent = Q_NULLPTR);

private:
	Ui::LoginClass ui;
};
