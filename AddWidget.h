#pragma once

#include <QWidget>
#include "ui_AddWidget.h"
#include "SQLConnect.cpp"


class AddWidget : public QWidget
{
	Q_OBJECT

public:
	AddWidget(QWidget *parent = nullptr);
	~AddWidget();

private slots:
        void on_commitBut_clicked();

        void on_resetBut_clicked();

private:
	Ui::AddWidgetClass ui;
};
