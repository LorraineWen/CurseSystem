#ifndef ADDCOURSEUI_H
#define ADDCOURSEUI_H
#include"coursecontroller.h"
#include <QFrame>

namespace Ui {
class AddCourseUi;
}

class AddCourseUi : public QFrame
{
    Q_OBJECT

public:
    explicit AddCourseUi(QWidget *parent = nullptr);
    ~AddCourseUi();

private slots:
    void on_addcoursebutton_clicked();
signals:
    void courseAdded();
private:
    Ui::AddCourseUi *ui;
    CourseController coursecontroller;
};
#endif // ADDCOURSEUI_H
