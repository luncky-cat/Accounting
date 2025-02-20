#include "SelectWidget.h"
//#include <QDateEdit>
//#include <QDateTime.h>
SelectWidget::SelectWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	initStyle();
	initSignal();
}

void SelectWidget::initStyle() {
	ui.beginDateE->setDisplayFormat("yyyy-MM-dd");
	ui.beginDateE->setDate(QDate::currentDate());
	ui.endDateE->setDate(QDate::currentDate());
}

void SelectWidget::initSignal() {
	QObject::connect(ui.selectBut,&QPushButton::clicked, this,&SelectWidget::on_selectBut_cli);
}

void SelectWidget::on_selectBut_cli() {
	QString beginTime = ui.beginDateE->text();
	qDebug()<< beginTime << endl;




}


SelectWidget::~SelectWidget()
{}
