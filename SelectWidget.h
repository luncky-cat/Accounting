#pragma once

#include <QWidget>
#include "ui_SelectWidget.h"

class SelectWidget : public QWidget
{
	Q_OBJECT
public:
	SelectWidget(QWidget *parent = nullptr);
	~SelectWidget();

private:
	Ui::SelectWidgetClass ui;
};
