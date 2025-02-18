#include "MyListWidget.h"
#include "SQLConnect.cpp"
#include<QString>
ListItemWidget::ListItemWidget(const QString& seq,const QString& time, const QString& usage, const QString& amount, QWidget* parent)
{
	QHBoxLayout* HLayout = new QHBoxLayout(this);//水平布局
    QLabel* seqLa = new QLabel(seq,this);
    QLabel* timeLa = new QLabel(time, this);
    QLabel* usageLa = new QLabel(usage, this);
    QLabel* amountLa = new QLabel(amount, this);
    QPushButton* delBut = new QPushButton("删除", this);
    QPushButton* modBut = new QPushButton("修改", this);
    QPushButton* reBut = new QPushButton("备注", this);
    HLayout->addWidget(seqLa);
    HLayout->addWidget(timeLa);
    HLayout->addWidget(usageLa);
    HLayout->addWidget(amountLa);
    HLayout->addWidget(delBut);
    HLayout->addWidget(modBut);
    HLayout->addWidget(reBut);
    initSignals();   //连接信号槽 
    setLayout(HLayout);
}

void ListItemWidget::initSignals()
{

}




CustomListWidget::CustomListWidget(QWidget* parent):QWidget(parent)
{
    QVBoxLayout* Vlayout = new QVBoxLayout(this);
    QHBoxLayout* Hlayout = new QHBoxLayout(this);
    QLabel* seq = new QLabel("序号");
    QLabel* time = new QLabel("日期");    
    QLabel* amount = new QLabel("金额");
    QLabel* usage = new QLabel("用途");
    QLabel* option = new QLabel("操作");
    Hlayout->addWidget(seq);
    Hlayout->addWidget(time);
    Hlayout->addWidget(usage);
    Hlayout->addWidget(amount);
    Hlayout->addWidget(option);

    MySQLConnection &msql = MySQLConnection::getInstance();
    sql::ResultSet* res=msql.executeQuery("select * from OverheadItems");
    QListWidget* listWidget = new QListWidget(this);
    listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    if (res) {
        unsigned int seq = 1;
        while (res->next()) {
            std::string date = res->getString("useTime");
            double amount = res->getDouble("amount");
            std::string usage=res->getString("usage");
            ListItemWidget* itemWidget = new ListItemWidget(
                QString::number(seq++),
                QString::fromStdString(date),
                QString::number(amount),
                QString::fromStdString(usage),
                this
            );
            // 创建 QListWidgetItem，并将 ListItemWidget 添加到其中
            QListWidgetItem* item = new QListWidgetItem(listWidget);
            item->setSizeHint(itemWidget->sizeHint());  // 设置项的大小
            // 将 ListItemWidget 插入到 QListWidget 中
            listWidget->setItemWidget(item, itemWidget);
        }
    }
    else {
        std::cout << "No results found!" << std::endl;
    }

    Vlayout->addLayout(Hlayout);
    Vlayout->addWidget(listWidget);
    setLayout(Vlayout);
}
