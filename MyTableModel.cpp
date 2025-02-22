#include "MyTableModel.h"
#include <QVariant>

MyTableModel::MyTableModel(QObject *parent, QSqlDatabase db)
    : QSqlTableModel(parent, db)
{
}

// 重写列数，增加一列
int MyTableModel::columnCount(const QModelIndex &parent) const
{
    return QSqlTableModel::columnCount(parent) + 1;  // 数据表的列数 + 1（删除按钮）
}

// 重写数据访问函数
QVariant MyTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    int originalColumnCount = QSqlTableModel::columnCount();

    // 如果是删除按钮列，显示“删除”字样
    if (role == Qt::DisplayRole && index.column() == originalColumnCount) {
        return "删除";  // 删除按钮文字
    }

    // 其他列使用父类的实现
    return QSqlTableModel::data(index, role);
}

QVariant MyTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
    {
        int originalColumnCount = QSqlTableModel::columnCount();

        if (section == originalColumnCount)
            return "删除操作";  // 删除列的列名
    }
    return QSqlTableModel::headerData(section, orientation, role);
}
Qt::ItemFlags MyTableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;
    int originalColumnCount = QSqlTableModel::columnCount();
    auto it=index.column();
    if (index.column() < originalColumnCount) {
        return Qt::ItemIsEditable | QSqlTableModel::flags(index);
    }
    return QSqlTableModel::flags(index);
}
