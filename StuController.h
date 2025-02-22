#ifndef STUCONTROLLER_H
#define STUCONTROLLER_H
#include "StudentDao.h"
class StuController
{
public:
     bool addstudent(std::string name,char gender,QString birthday,std::string hometown,int classid,int majorid);
     bool deletestudent(int id);
     bool deletescore(int id);
     MyTableModel& querystudentbyid(int id);
     QSqlTableModel& queryscorebyid(int id);
     QSqlQueryModel& querystuscorebyid(int id);
     MyTableModel& querystudentbyname(std::string name);
     MyTableModel& queryall();
     QSqlTableModel& queryallscore();
private:
    StudentDao dao;
};

#endif // STUCONTROLLER_H
