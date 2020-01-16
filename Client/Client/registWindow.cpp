#include "registWindow.h"
#include "Login.h"
#include <QDebug>
#include <QMessageBox>
#include "NetWorkHandler/ClientRegist.h"
#include "NetWorkHandler/NetWorkHandler.h"
#include "Entity/Entity.h"
#include <QHostAddress>

registWindow::registWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.passwdEdit->setEchoMode(QLineEdit::PasswordEchoOnEdit);
	ui.confirmEdit->setEchoMode(QLineEdit::Password);
	isName = isConfirm = isPassword = false;

	ui.nameEdit->installEventFilter(this);
	ui.passwdEdit->installEventFilter(this);
	ui.confirmEdit->installEventFilter(this);

	regist = new QTcpSocket();
	regist->connectToHost(QHostAddress(HostIp), Port);
}

registWindow::~registWindow()
{
}

//************************************
// Method:    registClicked
// FullName:  registWindow::registClicked
// Access:    public 
// Returns:   void
// Qualifier:注册账号之后返回初始界面
//************************************
void registWindow::registClicked()
{
	if(isSuccess())
	{
		//正确处理之后
		NetWorkHandler package(NetWorkHandler::regist);
		package["name"] = ui.nameEdit->text();
		package["password"] = ui.passwdEdit->text();
		package["type"] = NetWorkHandler::regist;

		ClientRegist *cr = new ClientRegist(regist);
		cr->run(package);

		connect(regist, SIGNAL(readyRead()), this, SLOT(registSlot()));
	}
	else
	{
		return;
	}
}
void registWindow::registSlot()
{
	NetWorkHandler nh;
	QByteArray byteArray = this->regist->readAll();
	int len = 0;

	while (len = nh.unpack(byteArray) > 0)
	{
		if (nh.getType() == NetWorkHandler::success)
		{
			QMessageBox *mss = new QMessageBox(QMessageBox::Information,
				QString::fromLocal8Bit("注册成功")
				, QString::fromLocal8Bit("注册账号成功"));
			mss->show();
			return;
		}
		else
		{
			QMessageBox *mss = new QMessageBox(QMessageBox::Information,
				QString::fromLocal8Bit("注册失败"),
				QString::fromLocal8Bit("注册账号已存在"));
			mss->show();
			return;
		}
	}
}
void registWindow::loginSlot()
{
	NetWorkHandler nh;
	QByteArray byteArray = this->regist->readAll();
	int len = 0;

	while (len = nh.unpack(byteArray) > 0)
	{
		if (nh.getType() == NetWorkHandler::success)
		{
			MainWindow *mainWin = new MainWindow();
			mainWin->show();
			mainWin->setName(ui.nameEdit->text());
			close();
			return;
		}
		else
		{
			QMessageBox *mss = new QMessageBox(QMessageBox::Information,
				QString::fromLocal8Bit("注册失败"),
				QString::fromLocal8Bit("注册账号已存在"));
			mss->show();
			return;
		}
	}
}
void registWindow::setName(const QString & name)
{
	ui.nameEdit->setText(name);
}

//************************************
// Method:    eventFilter
// FullName:  registWindow::eventFilter
// Access:    public 
// Returns:   bool
// Qualifier:事件过滤器
// Parameter: QObject * watched 监听元件
// Parameter: QEvent * event  监听事件
//************************************
bool registWindow::eventFilter(QObject * watched, QEvent * event)
{
	if (watched == ui.nameEdit) // 用户名文本框失焦事件处理
	{
		if (event->type()==QEvent::FocusOut)
		{
			//QFocusEvent *foevent = (QFocusEvent*) event;
			//只允许数字字母以及下划线
			QRegExp reg("\\w+");
			if (!reg.exactMatch(ui.nameEdit->text()))
			{
				ui.passwdEdit->setReadOnly(true);
				ui.confirmEdit->setReadOnly(true);
				isName = false;
				//qDebug() << isName;
			}
			else
			{
				ui.passwdEdit->setReadOnly(false);
				ui.confirmEdit->setReadOnly(false);
				isName = true;
				//qDebug() << isName;
			}
		}
	}

	else if (watched == ui.passwdEdit)
	{
		if (event->type() == QEvent::FocusOut)
		{
			QString password = ui.passwdEdit->text();
			if (password.isEmpty() || password.indexOf(" ") != -1)
			{
				isPassword = false;
			}
			else
			{
				isPassword = true;
			}
		}
	}

	else if(watched==ui.confirmEdit)
	{
		if (event->type() == QEvent::FocusOut)
		{
			if (ui.confirmEdit->text() != ui.passwdEdit->text())
			{
				isConfirm = false;
			}
			else
			{
				isConfirm = true;
			}
		}
	}
	else
	{
		return false;
	}

	return false;
}
//************************************
// Method:    isSuccess
// FullName:  registWindow::isSuccess
// Access:    public 
// Returns:   bool
// Qualifier:判断注册信息是否完全合法
//************************************
bool registWindow::isSuccess()
{
	if (!isName)
	{
		QMessageBox *mss = new QMessageBox(QMessageBox::Warning,
			QString::fromLocal8Bit("注册失败"),
			QString::fromLocal8Bit("用户应当仅含数字,字母或下划线!"));
		mss->show();
		return false;
	}
	else if (!isPassword)
	{

		QMessageBox *mss = new QMessageBox(QMessageBox::Warning,
			QString::fromLocal8Bit("注册失败"),
			QString::fromLocal8Bit("密码不允许含有空白字符!\n请重新输入密码并再次确认!"));
		mss->show();
		ui.passwdEdit->clear();
		ui.confirmEdit->clear();
		return false;
	}
	else if (!isConfirm)
	{
		QMessageBox *mss = new QMessageBox(QMessageBox::Warning,
			QString::fromLocal8Bit("注册失败"),
			QString::fromLocal8Bit("验证密码与密码不一致"));
		mss->show();
		ui.confirmEdit->clear();
		return false;
	}
	return true;
}
void registWindow::loginClicked()
{
	if (isSuccess())
	{
		//正确处理之后
		NetWorkHandler package(NetWorkHandler::regist);
		package["name"] = ui.nameEdit->text();
		package["password"] = ui.passwdEdit->text();
		package["type"] = NetWorkHandler::login;

		ClientRegist *cr = new ClientRegist(regist);
		cr->run(package);

		connect(regist, SIGNAL(readyRead()), this, SLOT(loginSlot()));
	}
	else
	{
		return;
	}
}
