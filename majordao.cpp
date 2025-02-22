#include "majordao.h"
#include<QSqlError>
#include"MySqlUtils.h"
bool MajorDao::addmajordao(std::string collegename,std::string major_name)
{
    MySqlUtils* util=MySqlUtils::get_instance();
    QSqlTableModel model(nullptr, util->get_db());
    model.setTable("majors");
    int row = model.rowCount();
    model.insertRow(row);
    model.setData(model.index(row, model.fieldIndex("major_name")), QString::fromStdString(major_name));
    model.setData(model.index(row, model.fieldIndex("college_name")), QString::fromStdString(collegename));
    if (model.submitAll()) {
        return true;
    } else {
        qDebug() << "Failed to add majors: " << model.lastError().text();
        return false;
    }
}
bool MajorDao::deletemajordao(int id)
{
    MyTableModel model;
    model.setTable("majors");
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
MyTableModel& MajorDao::querymajorbyname(std::string name)
{
    auto model =new MyTableModel();
    model->setTable("majors");
    model->setFilter(QString("major_name = '%1'").arg(QString::fromStdString(name)));
    model->select();
    return *model;
}
MyTableModel& MajorDao::queryalldao()
{
    auto model = new MyTableModel();
    model->setTable("majors");  // 设置表格为 "majors"

    if (!model->select()) {
        // 查询失败，输出错误信息
        qDebug() << "Error loading data from majors table:" << model->lastError().text();
    }
    return *model;
}

MyTableModel& MajorDao::querymajorbyid(int id)
{
    auto model =new MyTableModel();
    model->setTable("majors");
    model->setFilter(QString("major_id = '%1'").arg(id));
    model->select();
    return *model;
}
