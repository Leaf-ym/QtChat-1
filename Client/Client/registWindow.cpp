#include "registWindow.h"
#include "Login.h"
#include <QDebug>
#include <QMessageBox>
#include "Entity.h"

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
	}
	else
	{
		return;
	}

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
	
}
