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
// Qualifier:ע���˺�֮�󷵻س�ʼ����
//************************************
void registWindow::registClicked()
{
	if(isSuccess())
	{
		//��ȷ����֮��
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
				QString::fromLocal8Bit("ע��ɹ�")
				, QString::fromLocal8Bit("ע���˺ųɹ�"));
			mss->show();
			return;
		}
		else
		{
			QMessageBox *mss = new QMessageBox(QMessageBox::Information,
				QString::fromLocal8Bit("ע��ʧ��"),
				QString::fromLocal8Bit("ע���˺��Ѵ���"));
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
				QString::fromLocal8Bit("ע��ʧ��"),
				QString::fromLocal8Bit("ע���˺��Ѵ���"));
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
// Qualifier:�¼�������
// Parameter: QObject * watched ����Ԫ��
// Parameter: QEvent * event  �����¼�
//************************************
bool registWindow::eventFilter(QObject * watched, QEvent * event)
{
	if (watched == ui.nameEdit) // �û����ı���ʧ���¼�����
	{
		if (event->type()==QEvent::FocusOut)
		{
			//QFocusEvent *foevent = (QFocusEvent*) event;
			//ֻ����������ĸ�Լ��»���
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
// Qualifier:�ж�ע����Ϣ�Ƿ���ȫ�Ϸ�
//************************************
bool registWindow::isSuccess()
{
	if (!isName)
	{
		QMessageBox *mss = new QMessageBox(QMessageBox::Warning,
			QString::fromLocal8Bit("ע��ʧ��"),
			QString::fromLocal8Bit("�û�Ӧ����������,��ĸ���»���!"));
		mss->show();
		return false;
	}
	else if (!isPassword)
	{

		QMessageBox *mss = new QMessageBox(QMessageBox::Warning,
			QString::fromLocal8Bit("ע��ʧ��"),
			QString::fromLocal8Bit("���벻�����пհ��ַ�!\n�������������벢�ٴ�ȷ��!"));
		mss->show();
		ui.passwdEdit->clear();
		ui.confirmEdit->clear();
		return false;
	}
	else if (!isConfirm)
	{
		QMessageBox *mss = new QMessageBox(QMessageBox::Warning,
			QString::fromLocal8Bit("ע��ʧ��"),
			QString::fromLocal8Bit("��֤���������벻һ��"));
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
		//��ȷ����֮��
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
