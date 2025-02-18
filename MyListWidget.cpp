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

    connect(delBut, &QPushButton::clicked, this, [this,seqLa]() {
        MySQLConnection::getInstance().DeleteById(seqLa->text().toStdString());//删除数据
        //列表删除数据项目,触发，整个列表框重新刷新渲染，数据不变   得到行号或者其余有用的数据，然后删除
        });
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
        while (res->next()) {
            int id = res->getInt("itemId");
            std::string date = res->getString("useTime");
            double amount = res->getDouble("amount");
            std::string usage=res->getString("usage");
            ListItemWidget* itemWidget = new ListItemWidget(
                QString::number(id),
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

void CustomListWidget::deleteItem() {
    // 获取当前选中的 QListWidgetItem
    //QListWidgetItem* selectedItem = this->currentItem();
    //if (selectedItem) {
    //    // 获取该项的行号
    //    int row = listWidget->row(selectedItem);
    //    // 在这里，你可以根据行号删除数据库中的记录等操作
    //    deleteFromDatabase(row);
    //    // 删除 QListWidget 中对应的项
    //    delete listWidget->takeItem(row);  // 从列表中删除项
    //}
}

