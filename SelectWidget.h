#ifndef SELECTWIDGET_H
#define SELECTWIDGET_H
#include <QWidget>
#include "ui_SelectWidget.h"
#include<QlistView.h>
#include<qdebug.h>

class SelectWidget : public QWidget
{
	Q_OBJECT
public:
	SelectWidget(QWidget *parent = nullptr);
	void initStyle();
	void initSignal();
	~SelectWidget();
private slots:
	void on_selectBut_cli();
private:
	Ui::SelectWidgetClass ui;
};
#endif //SELECTWIDGET_H