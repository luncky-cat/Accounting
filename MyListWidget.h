#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDebug>
#include <QListWidget>
#include <QPainter>
#include <QStandardItemModel>
#include <QStyledItemDelegate>

class MyItemDelegate : public QStyledItemDelegate {
    Q_OBJECT
public:
    MyItemDelegate(QObject* parent = nullptr) : QStyledItemDelegate(parent) {}
    void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const override {
        painter->save();

        // 获取数据
        QString data = index.data(Qt::DisplayRole).toString();

        // 绘制按钮A
        QRect rectA = option.rect;
        rectA.setWidth(rectA.width() / 3);
        painter->drawText(rectA, Qt::AlignCenter, data);

        // 绘制按钮B
        QRect rectB = option.rect;
        rectB.moveLeft(rectA.right());
        rectB.setWidth(rectB.width() / 2);
        painter->drawText(rectB, Qt::AlignCenter, data);

        // 绘制按钮C
        QRect rectC = option.rect;
        rectC.moveLeft(rectB.right());
        painter->drawText(rectC, Qt::AlignCenter, data);

        painter->restore();
    }
signals:
    void buttonClicked(const QModelIndex& index, char button) const;
};

class MyListModel : public QAbstractListModel {
    Q_OBJECT

public:
    MyListModel(QObject* parent = nullptr) : QAbstractListModel(parent) {}

    int rowCount(const QModelIndex& parent = QModelIndex()) const override {
        return dataList.size();
    }

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override {
        if (index.isValid() && role == Qt::DisplayRole) {
            return dataList.at(index.row());
        }
        return QVariant();
    }

    void addItem(const QString& item) {
        beginInsertRows(QModelIndex(), dataList.size(), dataList.size());
        dataList.append(item);
        endInsertRows();
    }

private:
    QVector<QString> dataList;
};

class ShowWidget: public QWidget {
    Q_OBJECT

public:
    ShowWidget(QWidget* parent = nullptr) : QWidget(parent) {
        // 设置视图
        listView.setModel(&model);
        listView.setItemDelegate(new MyItemDelegate(this));
    }
private:
    QListView listView;
    MyListModel model;
};