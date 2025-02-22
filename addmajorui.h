#ifndef ADDMAJORUI_H
#define ADDMAJORUI_H

#include <QFrame>
#include"majorcontroller.h"
namespace Ui {
class AddMajorUi;
}

class AddMajorUi : public QFrame
{
    Q_OBJECT

public:
    explicit AddMajorUi(QWidget *parent = nullptr);
    ~AddMajorUi();

private slots:
    void on_addmajorbutton_clicked();
signals:
    void majorAdded();
private:
    Ui::AddMajorUi *ui;
    MajorController majorcontroller;
};

#endif // ADDMAJORUI_H
