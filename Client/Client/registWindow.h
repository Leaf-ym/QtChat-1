#pragma once

#include <QWidget>
#include "ui_registWindow.h"

class registWindow : public QWidget
{
	Q_OBJECT

public:
	registWindow(QWidget *parent = Q_NULLPTR);
	~registWindow();

private:
	Ui::registWindow ui;

public slots:
	void loginClicked();
	void registClicked();

public:
	void setName(const QString& name);
	void closeEvent(QCloseEvent *event);
};
