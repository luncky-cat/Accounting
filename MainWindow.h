#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
#include <QStackedWidget>

//页面类
#include "AddWidget.h"
#include "SelectWidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_addAction_triggered(bool checked);
    void on_selectAction_triggered(bool checked);
private:
    Ui::MainWindowClass ui;
    QStackedWidget* StackedWidget;//管理
    SelectWidget* selectWidget;//查询页面
    AddWidget* addWidget;//添加页面
};
