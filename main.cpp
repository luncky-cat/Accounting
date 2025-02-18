#include "MainWindow.h"
#include <QtWidgets/QApplication>
#include <QTextCodec>
//#pragma execution_character_set("utf-8")
int main(int argc, char *argv[])
{
   // QTextCodec* codec = QTextCodec::codecForName("UTF-8");//或者"GBK",不分大小写
   // QTextCodec::setCodecForLocale(codec);
   // QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);
   // QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    MainWindow w;
    w.show();
    return a.exec();
}
