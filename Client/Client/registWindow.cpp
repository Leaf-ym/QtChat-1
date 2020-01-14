#include "registWindow.h"
#include "Login.h"
registWindow::registWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

registWindow::~registWindow()
{
}

void registWindow::registClicked()
{
	Login *login = new Login(0);
	login->show();
	close();
}
void registWindow::loginClicked()
{

}
