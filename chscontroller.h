#ifndef CHSCONTROLLER_H
#define CHSCONTROLLER_H
#include"chsdao.h"
class ChsController
{
public:
    bool addchs(int student_id,int course_id,int score);
    bool deletechs(int id);
    MyTableModel& querychsbyid(int id);
    MyTableModel& querychsbyname(std::string name);
    MyTableModel& queryall();
private:
    ChsDao dao;
};

#endif // CHSCONTROLLER_H
