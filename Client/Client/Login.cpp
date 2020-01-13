#include "Login.h"
#include <QLineEdit>
Login::Login(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.passwdEdit->setEchoMode(QLineEdit::Password);
}
