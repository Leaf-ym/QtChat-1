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
	QString name = ui.nameEdit->text();
	if (!name.isEmpty())
	{
		login->setName(name);
	}
	login->show();
	close();
}
void registWindow::setName(const QString & name)
{
	ui.nameEdit->setText(name);
}
void registWindow::closeEvent(QCloseEvent * event)
{
}
void registWindow::loginClicked()
{
	Login *login = new Login();
	login->show();
	close();
}
