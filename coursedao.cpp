#include "coursedao.h"
#include"MySqlUtils.h"
bool CourseDao::addcoursedao(std::string name,int credits)
{
    MySqlUtils* util=MySqlUtils::get_instance();
    QSqlTableModel model(nullptr, util->get_db());
    model.setTable("courses");
    int row = model.rowCount();
    model.insertRow(row);
    model.setData(model.index(row, model.fieldIndex("course_name")), QString::fromStdString(name));
    model.setData(model.index(row, model.fieldIndex("credits")), credits);
    if (model.submitAll()) {
        return true;
    } else {
        qDebug() << "Failed to add courses: " << model.lastError().text();
        return false;
    }
}
bool CourseDao::deletecoursedao(int id)
{
    MyTableModel model;
    model.setTable("courses");
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
MyTableModel& CourseDao::querycoursebyname(std::string name)
{
    auto model =new MyTableModel();
    model->setTable("courses");
    model->setFilter(QString("course_name = '%1'").arg(QString::fromStdString(name)));
    model->select();
    return *model;
}
MyTableModel& CourseDao::queryalldao()
{
    auto model = new MyTableModel();
    model->setTable("courses");  // 设置表格为 "courses"

    if (!model->select()) {
        // 查询失败，输出错误信息
        qDebug() << "Error loading data from courses table:" << model->lastError().text();
    }
    return *model;
}

MyTableModel& CourseDao::querycoursebyid(int id)
{
    auto model =new MyTableModel();
    model->setTable("courses");
    model->setFilter(QString("course_id = '%1'").arg(id));
    model->select();
    return *model;
}

