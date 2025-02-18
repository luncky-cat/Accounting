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

}

void AddWidget::on_commitBut_clicked() {
	MySQLConnection &query =MySQLConnection::getInstance();
    QString useTime =ui.useTime->text() ;  // 假设从界面获取到的日期字符串
    QString amount = ui.amount->text();    // 假设从界面获取到的金额
    QString usage = ui.usaage->currentText();         // 假设从界面获取到的用途
    QString remark =ui.plainTextEdit->toPlainText();    // 假设从界面获取到的备注
    //// 将 amountStr 转换为 double 类型
    //double amount = amountStr.toDouble();
    std::string useTimeStr = useTime.toStdString();
    std::string amountStr = amount.toStdString();
    std::string usageStr = usage.toStdString();
    std::string remarkStr = remark.toStdString();

    std::string queryStr = "INSERT INTO OverheadItems (useTime, amount, `usage`, remark) "
        "VALUES ('" + useTimeStr + "', " + amountStr + ", '" + usageStr + "', '" + remarkStr + "');";
    query.executeQuery(queryStr);
    /*if (query.executeQuery(queryStr)) {
        qDebug() << "数据插入成功！";
    }*/
    //else {
    //    //qDebug() << "插入失败:" << query.lastError();
    //}


}