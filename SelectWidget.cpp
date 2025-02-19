#include "SelectWidget.h"

SelectWidget::SelectWidget(QWidget *parent)
	: QWidget(parent)
{
    //// 创建分类标签和组合框
    //QLabel* tLable = new QLabel(QString("分类"), SelectWidget);
    //QComboBox* comboBox = new QComboBox(SelectWidget);
    //comboBox->addItem("全部");
    //comboBox->addItem("饮食");
    //comboBox->addItem("教育");
    //comboBox->addItem("出行");
    //comboBox->addItem("人际");
    //comboBox->addItem("住房");
    //comboBox->addItem("借贷");

    //// 创建时间范围标签和日期编辑框
    //QLabel* tipLable = new QLabel(QString("时间范围"), SelectWidget);
    //QDateEdit* dateEdit = new QDateEdit(SelectWidget);
    //dateEdit->setDisplayFormat("yyyy-MM-dd");  // 设置日期显示格式为 年-月-日
    //dateEdit->setDate(QDate::currentDate());   // 设置默认日期为当前日期
    //QDateEdit* dateEdit2 = new QDateEdit(SelectWidget);
    //dateEdit2->setDisplayFormat("yyyy-MM-dd");  // 设置日期显示格式为 年-月-日
    //dateEdit2->setDate(QDate::currentDate());   // 设置默认日期为当前日期

    //// 创建查询按钮
    //QPushButton* selectButton = new QPushButton(QString("查询"), SelectWidget);

    //// 创建水平布局，并将控件添加进去
    //QHBoxLayout* HLayout = new QHBoxLayout();
    //HLayout->addWidget(tLable);
    //HLayout->addWidget(comboBox);
    //HLayout->addWidget(tipLable);
    //HLayout->addWidget(dateEdit);
    //HLayout->addWidget(dateEdit2);
    //HLayout->addWidget(selectButton);
    //// 创建自定义列表控件
    //CustomListWidget* listWidget = new CustomListWidget(SelectWidget);
    //// 创建垂直布局并将控件添加进去
    //QVBoxLayout* VLayout = new QVBoxLayout(SelectWidget);
    //VLayout->addLayout(HLayout); // 将水平布局添加到垂直布局中
    //VLayout->addWidget(listWidget); // 将自定义列表控件添加到垂直布局中

    //// 设置 SelectWidget 的布局为 VLayout
    //SelectWidget->setLayout(VLayout);

    //// 创建 QStackedWidget
    //stackedWidget = new QStackedWidget(this);  // 创建 QStackedWidget

    //// 将 SelectWidget 添加到 QStackedWidget 中
    //stackedWidget->addWidget(SelectWidget);

    //// 设置 QStackedWidget 为 centralWidget
    //setCentralWidget(stackedWidget);

    //// 可选择的: 设置 QStackedWidget 的大小策略为扩展
    //stackedWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    //// 显示 SelectWidget (如果希望显示多个页面，可以在这里使用 setCurrentIndex(0) 或 setCurrentWidget(SelectWidget))
    //stackedWidget->setCurrentWidget(SelectWidget);  // 默认显示 SelectWidget 页面
	ui.setupUi(this);
}

SelectWidget::~SelectWidget()
{}
