#include "chsdao.h"
#include"MySqlUtils.h"
bool ChsDao::addchsdao(int student_id,int course_id,int score)
{
    MySqlUtils* util=MySqlUtils::get_instance();
    QSqlTableModel model(nullptr, util->get_db());
    model.setTable("course_selection");
    int row = model.rowCount();
    model.insertRow(row);
    model.setData(model.index(row, model.fieldIndex("student_id")),student_id);
    model.setData(model.index(row, model.fieldIndex("course_id")), course_id);
    model.setData(model.index(row,model.fieldIndex("score")),score);
    if (model.submitAll()) {
        return true;
    } else {
        qDebug() << "Failed to add chss: " << model.lastError().text();
        return false;
    }
}
bool ChsDao::deletechsdao(int id)
{
    MyTableModel model;
    model.setTable("course_selection");
    model.select();
    for (int row = 0; row < model.rowCount(); ++row)
    {
        if (model.data(model.index(row, 0)).toInt() == id)
        {
            if (model.removeRow(row))
            {
                model.submitAll();
                return true;
            }
            break;
        }
    }
    return false;
}
MyTableModel& ChsDao::querychsbyid(int studentid)
{
    auto model =new MyTableModel();
    model->setTable("course_selection");
    model->setFilter(QString("student_id = '%1'").arg(studentid));
    model->select();
    return *model;
}
MyTableModel& ChsDao::queryalldao()
{
    auto model = new MyTableModel();
    model->setTable("course_selection");

    if (!model->select()) {
        qDebug() << "Error loading data from chs table:" << model->lastError().text();
    }
    return *model;
}
