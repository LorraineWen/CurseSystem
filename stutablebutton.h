#ifndef STUTABLEBUTTON_H
#define STUTABLEBUTTON_H

#include <QStyledItemDelegate>
#include <QPushButton>
#include <QEvent>

class StuTableButton : public QStyledItemDelegate
{
    Q_OBJECT

public:
    explicit StuTableButton(QObject *parent = nullptr);

    // 重写绘制函数
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;

    // 重写事件处理函数
    bool editorEvent(QEvent *event, QAbstractItemModel *model,
                     const QStyleOptionViewItem &option, const QModelIndex &index) override;

signals:
    // 删除按钮点击信号
    void deleteButtonClicked(const QModelIndex &index);
};

#endif // STUTABLEBUTTON_H
