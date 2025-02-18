#include "AddWidget.h"

AddWidget::AddWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

AddWidget::~AddWidget()
{}

void AddWidget::on_resetBut_clicked() 
{
    // 判断误操作
    QMessageBox::StandardButton reply;
    reply=QMessageBox::question(NULL, "提示", "是否清空", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    if (reply==QMessageBox::Yes) {
        //重置内容
        ui.usaage->setCurrentIndex(0);
        ui.amount->setText(0);//置0
        ui.plainTextEdit->clear();//置空
    }
    //否则不做任何事
}

void AddWidget::on_commitBut_clicked() {
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(NULL, "提示", "是否提交", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes); 
    if (reply == QMessageBox::No) {
        return;
    }
	MySQLConnection &query =MySQLConnection::getInstance();
    QString useTime =ui.useTime->text() ;  // 假设从界面获取到的日期字符串
    QString amount = ui.amount->text();    // 假设从界面获取到的金额
    QString usage = ui.usaage->currentText();         // 假设从界面获取到的用途
    QString remark =ui.plainTextEdit->toPlainText();    // 假设从界面获取到的备注
    std::string useTimeStr = useTime.toStdString();
    std::string amountStr = amount.toStdString();
    std::string usageStr = usage.toStdString();
    std::string remarkStr = remark.toStdString();
    std::string queryStr = "INSERT INTO OverheadItems (useTime, amount, `usage`, remark) "
        "VALUES ('" + useTimeStr + "', " + amountStr + ", '" + usageStr + "', '" + remarkStr + "');";
    query.executeQuery(queryStr);

    //重置
    ui.usaage->setCurrentIndex(0);
    ui.amount->setText(0);//置0
    ui.plainTextEdit->clear();//置空
}