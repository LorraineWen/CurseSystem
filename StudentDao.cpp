#include"StudentDao.h"
#include<QSqlError>
#include"MySqlUtils.h"
bool StudentDao::addstudentdao(std::string name,char gender,QString birthday,std::string hometown,int classid,int majorid)
{
    QSqlTableModel model(nullptr, MySqlUtils::get_db());  // 创建 QSqlTableModel 实例
    model.setTable("students");  // 设置表名
    // 插入一行数据
    int row = model.rowCount();  // 获取当前行数
    model.insertRow(row);  // 插入新的一行
    // 为每一列设置数据
    model.setData(model.index(row, model.fieldIndex("name")), QString::fromStdString(name));
    model.setData(model.index(row, model.fieldIndex("gender")), QString(gender));
    model.setData(model.index(row, model.fieldIndex("birth_date")), birthday);
    model.setData(model.index(row,model.fieldIndex("hometown")),QString::fromStdString(hometown));
    model.setData(model.index(row,model.fieldIndex("class_id")),classid);
    model.setData(model.index(row,model.fieldIndex("major_id")),majorid);
    // 提交数据到数据库
    if (model.submitAll()) {
        return true;  // 插入成功
    } else {
        qDebug() << "Failed to add student: " << model.lastError().text();
        return false;  // 插入失败
    }
}


MyTableModel&  StudentDao::queryalldao()
{
    auto model =new MyTableModel();
    model->setTable("students");
    model->select();
    return *model;
}
QSqlTableModel& StudentDao::queryallscore()
{
    auto model =new QSqlTableModel();
    model->setTable("supplementaryexam");
    model->select();
    return *model;
}
bool StudentDao::deletestudentdao(int id)
{
    MyTableModel model;
    model.setTable("students");
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
bool StudentDao::deletescoredao(int id)
{
    MyTableModel model;
    model.setTable("supplementaryexam");
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
MyTableModel& StudentDao::querystudentbyid(int id)
{
    auto model =new MyTableModel();
    model->setTable("students");
    model->setFilter(QString("student_id = %1").arg(id));
    model->select();
    return *model;
}
QSqlTableModel& StudentDao::queryscorebyid(int id)
{
    auto model =new QSqlTableModel();
    model->setTable("supplementaryexam");
    model->setFilter(QString("student_id = %1").arg(id));
    model->select();
    return *model;
}
MyTableModel& StudentDao::querystudentbyname(std::string name)
{
    auto model =new MyTableModel();
    model->setTable("students");
    model->setFilter(QString("name = '%1'").arg(QString::fromStdString(name)));
    model->select();
    return *model;
}
QSqlQueryModel& StudentDao::querystuscorebyid(int id)
{
    QSqlQuery query(MySqlUtils::get_db());
    query.prepare("CALL GetClassScores(:classId)");
    query.bindValue(":classId", id);
    if (!query.exec()) {
        qDebug() << "Error executing stored procedure: " << query.lastError().text();
    }
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(std::move(query));
    if (model->lastError().isValid()) {
        qDebug() << "Error loading query result: " << model->lastError().text();
    }
    return *model;
}
