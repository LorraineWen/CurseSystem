#include "addmajorui.h"
#include "ui_addmajorui.h"

AddMajorUi::AddMajorUi(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::AddMajorUi)
{
    ui->setupUi(this);
}

AddMajorUi::~AddMajorUi()
{
    delete ui;
}

void AddMajorUi::on_addmajorbutton_clicked()
{
    QString majorname=this->ui->majorname->text();
    QString collegename=this->ui->collegename->text();
    majorcontroller.addmajor(majorname.toStdString(),collegename.toStdString());
    emit majorAdded();
    this->close();
}

