#include "SelectWidget.h"
#include <QVariant>

SelectWidget::SelectWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	initStyle();// 初始化样式表
	initSignal();  //初始化信号和槽
}

void SelectWidget::initStyle() {

	//设置时间控件
	ui.beginDateE->setDisplayFormat("yyyy-MM-dd");
	ui.beginDateE->setDate(QDate::currentDate());
	ui.endDateE->setDisplayFormat("yyyy-MM-dd");
	ui.endDateE->setDate(QDate::currentDate());

}

void SelectWidget::initSignal() {
	QObject::connect(ui.selectBut,&QPushButton::clicked, this,&SelectWidget::on_selectBut_cli);  //查询信号
}

void SelectWidget::on_selectBut_cli() {    //查询函数
	QDate BeginDate = ui.beginDateE->date();
	QDate EndDate = ui.endDateE->date();

	if (BeginDate>EndDate) {  //开始大于结束
		qDebug() << "BeginDate时间大" << endl;
		return;
	}

	QString beginTime = ui.beginDateE->text();
	QString endTime = ui.endDateE->text();
	QString usage= ui.usageCbox->currentText();
	QString excSql = "SELECT * FROM overheaditems WHERE useTime BETWEEN '" + beginTime + "' AND '" + endTime + "';";   //先加载所有数据不分类，后续优化

	MySQLConnection& r = MySQLConnection::getInstance();
	sql::ResultSet* res = r.executeQuery(excSql.toStdString());

	qDebug() << excSql << endl;

	if (!res) {   //无数据
		return;
	}
	//渲染listview
	updateListView(res);
}

void SelectWidget::updateListView(sql::ResultSet* res) {  //根据结果集合加载数据
		while (res->next()) {
			int id = res->getInt("itemId");  //Id
			std::string date = res->getString("useTime"); //使用时间
			double amount = res->getDouble("amount");  //金额
			std::string usage = res->getString("usage"); //用法
			
		/*	ListItemWidget* itemWidget = new ListItemWidget(
				QString::number(id),
				QString::fromStdString(date),
				QString::number(amount),
				QString::fromStdString(usage),
				this
			);*/
			//QListWidgetItem* item = new QListWidgetItem(listWidget);
			//item->setSizeHint(itemWidget->sizeHint());
			//listWidget->setItemWidget(item, itemWidget);
		}
}


SelectWidget::~SelectWidget()
{}
