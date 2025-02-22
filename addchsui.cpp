#include "addchsui.h"
#include "ui_addchsui.h"

AddChsUi::AddChsUi(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::AddChsUi)
{
    ui->setupUi(this);
}

AddChsUi::~AddChsUi()
{
    delete ui;
}
void AddChsUi::on_addchsbutton_clicked()
{
    int student_id=this->ui->studentid->text().toInt();
    int course_id=this->ui->courseid->text().toInt();
    int score=this->ui->score->text().toInt();
    chscontroller.addchs(student_id,course_id,score);
    emit chsAdded();
    this->close();
}
