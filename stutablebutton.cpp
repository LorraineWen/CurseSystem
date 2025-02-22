#include "StuTableButton.h"
#include <QApplication>
#include <QPainter>
#include <QStyleOptionButton>
#include <QMouseEvent>
#include <QPushButton>

StuTableButton::StuTableButton(QObject *parent)
    : QStyledItemDelegate(parent)
{
}

void StuTableButton::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.column() == index.model()->columnCount() - 1) {  // 只在最后一列显示删除按钮

        // 创建按钮样式
        QStyleOptionButton buttonOption;
        buttonOption.rect = option.rect;
        buttonOption.text = "删除";
        buttonOption.state = QStyle::State_Enabled;

        // 设置背景颜色和文字颜色
        buttonOption.palette.setColor(QPalette::Button, QColor(Qt::red));
        buttonOption.palette.setColor(QPalette::ButtonText, QColor(Qt::white));

        // 绘制按钮
        QApplication::style()->drawControl(QStyle::CE_PushButton, &buttonOption, painter);
    } else {
        // 调用父类的绘制方法，绘制其他列的内容
        QStyledItemDelegate::paint(painter, option, index);
    }
}

bool StuTableButton::editorEvent(QEvent *event, QAbstractItemModel *model,
                                 const QStyleOptionViewItem &option, const QModelIndex &index)
{
    // 如果点击的是删除按钮所在的列，发出删除按钮点击信号
    if (event->type() == QEvent::MouseButtonRelease && index.column() == index.model()->columnCount() - 1) {
        emit deleteButtonClicked(index);  // 触发删除信号
        return true;  // 事件被消费，防止触发编辑操作
    }

    // 如果点击的不是删除按钮列，则不干扰其他编辑事件
    return QStyledItemDelegate::editorEvent(event, model, option, index);
}
