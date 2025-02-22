#ifndef ADDCHSUI_H
#define ADDCHSUI_H
#include"chscontroller.h"
#include <QFrame>

namespace Ui {
class AddChsUi;
}

class AddChsUi : public QFrame
{
    Q_OBJECT

public:
    explicit AddChsUi(QWidget *parent = nullptr);
    ~AddChsUi();
signals:
    void chsAdded();
private slots:
    void on_addchsbutton_clicked();
private:
    Ui::AddChsUi *ui;
    ChsController chscontroller;
};
#endif // ADDCHSUI_H
