#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
#include <QDateEdit>
#include<QLabel.h>
#include<QPushButton>
#include<QHBoxLayout>
#include<QListView>
#include <QStackedWidget>
#include<AddWidget.h>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void initSelectWidget();
    void initAddWidget();
private slots:
    void on_addAction_triggered(bool checked);

    void on_selectAction_triggered(bool checked);

private:
    Ui::MainWindowClass ui;
    QStackedWidget* stackedWidget;
    QWidget* SelectWidget;//查询页面
    AddWidget* AddW;//添加页面
};
