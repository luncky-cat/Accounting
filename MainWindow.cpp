#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    StackedWidget = new QStackedWidget();
    selectWidget = new SelectWidget;
    addWidget = new AddWidget;
    StackedWidget->addWidget(selectWidget);
    StackedWidget->addWidget(addWidget);
    StackedWidget->setCurrentIndex(1);
}

MainWindow::~MainWindow()
{}

void MainWindow::on_addAction_triggered(bool checked)
{
    StackedWidget->setCurrentIndex(1);
}

void MainWindow::on_selectAction_triggered(bool checked)
{
    StackedWidget->setCurrentIndex(0);
}
