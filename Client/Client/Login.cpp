#include "Login.h"
#include <QLineEdit>
#include "NetWorkHandler/NetWorkHandler.h"
#include <QMessageBox>
#include "NetWorkHandler/ClientLogin.h"
#include <QHostAddress>
Login::Login(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.passwdEdit->setEchoMode(QLineEdit::Password);
	login = new QTcpSocket(this);
	login->connectToHost(QHostAddress(HostIp), Port);
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
	if (ui.nameEdit->text().isEmpty()||ui.passwdEdit->text().isEmpty())
	{
		QMessageBox *mss = new QMessageBox(QMessageBox::Warning,
			QString::fromLocal8Bit("µÇÂ¼Ê§°Ü"),
			QString::fromLocal8Bit("ÓÃ»§Ãû»òÃÜÂë²»ÄÜÎª¿Õ"));
		mss->show();
		return;
	}
	NetWorkHandler pakage(NetWorkHandler::login);
	pakage["name"] = ui.nameEdit->text();
	pakage["password"] = ui.passwdEdit->text();
	ClientLogin(login).run(pakage);

	connect(login, SIGNAL(readyRead()), this, SLOT(loginSlot()));
	/*
	MainWindow *mainWin = new MainWindow();
	mainWin->show();
	close();
	*/
}

void Login::loginSlot()
{
	NetWorkHandler nh;
	QByteArray byteArray = this->login->readAll();
	int len = 0;

	while (len = nh.unpack(byteArray) > 0)
	{
		if (nh.getType() == NetWorkHandler::success)
		{
			MainWindow *mainWin = new MainWindow();
			mainWin->setName(ui.nameEdit->text());
			mainWin->show();
			close();
			return;
		}
		else
		{
			QMessageBox *mss = new QMessageBox(QMessageBox::Information,
				QString::fromLocal8Bit("µÇÂ¼Ê§°Ü"),
				QString::fromLocal8Bit("ÕËºÅÃÜÂë´íÎó\n»òÕËºÅÒÑÔÚÏß"));
			mss->show();
			return;
		}
	}
}

void Login::setName(const QString & name)
{
	ui.nameEdit->setText(name);
}

