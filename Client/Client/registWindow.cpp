#include "registWindow.h"
#include "Login.h"
registWindow::registWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.passwdEdit->setEchoMode(QLineEdit::PasswordEchoOnEdit);
	ui.confirmEdit->setEchoMode(QLineEdit::Password);
}

registWindow::~registWindow()
{
}

void registWindow::registClicked()
{
	Login *login = new Login();
	login->show();
	close();
}
void registWindow::loginClicked()
{

}
