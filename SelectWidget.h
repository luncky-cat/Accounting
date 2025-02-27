#ifndef SELECTWIDGET_H
#define SELECTWIDGET_H
#include <QWidget>
#include "ui_SelectWidget.h"
#include<QlistView.h>
#include<qdebug.h>
#include "SQLConnect.cpp"

class SelectWidget : public QWidget
{
	Q_OBJECT
public:
	SelectWidget(QWidget *parent = nullptr);
	void initStyle();
	void initSignal();
	void updateListView(sql::ResultSet* re);
	~SelectWidget();
private slots:
	void on_selectBut_cli();
private:
	Ui::SelectWidgetClass ui;
};
#endif //SELECTWIDGET_H