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
	registWin = new registWindow();
	//registWin->setParent(NULL);
	registWin->show();
	close();
}

void Login::loginClicked()
{
	MainWindow *mainWin = new MainWindow();
	mainWin->show();
	close();
}
