#ifndef ADDSTUDENTUI_H
#define ADDSTUDENTUI_H
#include"StuController.h"
#include <QFrame>

namespace Ui {
class AddStudentUi;
}

class AddStudentUi : public QFrame
{
    Q_OBJECT

public:
    explicit AddStudentUi(QWidget *parent = nullptr);
    ~AddStudentUi();
signals:
    void studentAdded();
private slots:
    void on_addstubutton_clicked();

private:
    Ui::AddStudentUi *ui;
    StuController stucontroller;
};

#endif // ADDSTUDENTUI_H
