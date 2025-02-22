#include"StuController.h"

    bool StuController::addstudent(std::string name,char gender,QString birthday,std::string hometown,int classid,int majorid)
    {
        return dao.addstudentdao(name,gender,birthday,hometown,classid,majorid);
    }
    bool StuController::deletestudent(int id)
    {
        return dao.deletestudentdao(id);
    }
    bool StuController::deletescore(int id)
    {
        return dao.deletescoredao(id);
    }
   MyTableModel& StuController::querystudentbyid(int id)
    {
        return dao.querystudentbyid(id);
    }
    QSqlTableModel& StuController::queryscorebyid(int id)
    {
        return dao.queryscorebyid(id);
    }
    QSqlQueryModel& StuController::querystuscorebyid(int id)
    {
        return dao.querystuscorebyid(id);
    }
    MyTableModel& StuController::querystudentbyname(std::string name)
    {
        return dao.querystudentbyname(name);
    }
    MyTableModel& StuController::queryall()
    {
        return dao.queryalldao();
    }
    QSqlTableModel& StuController::queryallscore()
    {
        return dao.queryallscore();
    }
