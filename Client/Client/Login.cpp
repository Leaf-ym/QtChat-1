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

	QString name = ui.nameEdit->text();
	if (!name.isEmpty())
	{
		registWin->setName(name);
	}

	registWin->show();
	close();
}

void Login::loginClicked()
{
	MainWindow *mainWin = new MainWindow();
	mainWin->show();
	close();
}

void Login::setName(const QString & name)
{
	ui.nameEdit->setText(name);
}

