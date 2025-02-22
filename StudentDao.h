#ifndef STUDENTDAO_H
#define STUDENTDAO_H
#include"Student.h"
#include"MyTableModel.h"
class StudentDao
{
public:
    bool addstudentdao(std::string name,char gender,QString birthday,std::string hometown,int classid,int majorid);
    virtual bool deletestudentdao(int id);
    virtual bool deletescoredao(int id);
    virtual MyTableModel& querystudentbyid(int id);
     virtual QSqlTableModel& queryscorebyid(int id);
    virtual QSqlQueryModel& querystuscorebyid(int id);
    virtual MyTableModel& querystudentbyname(std::string name);
    virtual MyTableModel&  queryalldao();
    virtual QSqlTableModel& queryallscore();
};

#endif // STUDENTDAO_H
