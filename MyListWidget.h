#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDebug>
#include <QListWidget>
class ListItemWidget : public QWidget {   //自定义的列表项
    Q_OBJECT
public:
    ListItemWidget(const QString& seq, const QString& time, const QString& usage, const QString& amount, QWidget* parent);
private:
    void initSignals();
};
class CustomListWidget : public QWidget {    //列表整体
    Q_OBJECT
public:
    CustomListWidget(QWidget* parent = nullptr);
private slots:
    void deleteItem();
};

 