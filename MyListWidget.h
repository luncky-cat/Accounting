#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDebug>
#include <QListWidget>
class ListItemWidget : public QWidget {   //自定义的列表项
    Q_OBJECT
public:
    //ListItemWidget(const QString& time, const QString& usage, const QString& amount, QWidget* parent);
    ListItemWidget(const QString& seq, const QString& time, const QString& usage, const QString& amount, QWidget* parent);
private:
   
    void initSignals();
//signals:
//    void buttonClicked();
//private slots:
//    void onButtonClick() {
//        emit buttonClicked();  // 发出信号
//    }
};
  
class CustomListWidget : public QWidget {    //列表整体
    Q_OBJECT
public:
    CustomListWidget(QWidget* parent = nullptr);
//signals:
//    void buttonClicked(const QString& text);
//
//private slots:
//    void onButtonClicked() {
//        // 在此处理按钮点击事件
//        qDebug() << "Button clicked!";
//    }
};

 