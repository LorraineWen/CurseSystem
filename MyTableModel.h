#ifndef MyTableModel_H
#define MyTableModel_H

#include <QSqlTableModel>

class MyTableModel : public QSqlTableModel
{
    Q_OBJECT

public:
    explicit MyTableModel(QObject *parent = nullptr, QSqlDatabase db = QSqlDatabase());

    // 重写列数，增加一列
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    // 重写数据访问函数
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    // 重写列头数据
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
};

#endif // MyTableModel_H
