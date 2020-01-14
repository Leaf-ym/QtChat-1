#pragma once

#include <QWidget>
#include "ui_registWindow.h"
#include <QRegExp>
class registWindow : public QWidget
{
	Q_OBJECT

public:
	registWindow(QWidget *parent = Q_NULLPTR);
	~registWindow();

private:
	Ui::registWindow ui;

	bool isName;
	bool isPassword;
	bool isConfirm;

public slots:
	void loginClicked();
	void registClicked();

public:
	void setName(const QString& name);

	bool eventFilter(QObject *watched, QEvent *event);
	bool isSuccess();
};
