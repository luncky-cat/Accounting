#ifndef SELECTWIDGET_H
#define SELECTWIDGET_H
#include <QWidget>
#include "ui_SelectWidget.h"
#include<QlistView.h>

class SelectWidget : public QWidget
{
	Q_OBJECT
public:
	SelectWidget(QWidget *parent = nullptr);
	~SelectWidget();
	//QListView* showData;//列表整体
private:
	Ui::SelectWidgetClass ui;
};
#endif //SELECTWIDGET_H