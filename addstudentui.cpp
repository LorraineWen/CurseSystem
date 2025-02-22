#include "addstudentui.h"
#include "ui_addstudentui.h"

AddStudentUi::AddStudentUi(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::AddStudentUi)
{
    ui->setupUi(this);
}

AddStudentUi::~AddStudentUi()
{
    delete ui;
}

void AddStudentUi::on_addstubutton_clicked()
{
    QString name=this->ui->name->text();
    char gender;
    if (ui->sex_M->isChecked()) {
        gender = 'M';
    } else if (ui->sex_F->isChecked()) {
        gender = 'F';
    } else {
        gender = '\0';
    }
    QString birthday=this->ui->birthdate->text();
    QString addr=this->ui->Addr->text();
    int classid=this->ui->classid->text().toInt();
    int majorid=this->ui->majorid->text().toInt();
    stucontroller.addstudent(name.toStdString(),gender,birthday,addr.toStdString(),classid,majorid);
    emit studentAdded();
    this->close();
}
