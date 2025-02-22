#include "addcourseui.h"
#include "ui_addcourseui.h"

AddCourseUi::AddCourseUi(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::AddCourseUi)
{
    ui->setupUi(this);
}

AddCourseUi::~AddCourseUi()
{
    delete ui;
}

void AddCourseUi::on_addcoursebutton_clicked()
{
    QString coursename=this->ui->coursename->text();
    int credits=this->ui->credits->text().toInt();
    coursecontroller.addcourse(coursename.toStdString(),credits);
    emit courseAdded();
    this->close();
}

