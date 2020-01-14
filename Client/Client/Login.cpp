#include "Login.h"
#include <QLineEdit>
Login::Login(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.passwdEdit->setEchoMode(QLineEdit::Password);
}

void Login::registClicked()
{
	registWindow *registWin;
	registWin = new registWindow(0);
	//registWin->setParent(NULL);
	registWin->show();
	close();
}
