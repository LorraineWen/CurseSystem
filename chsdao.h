#ifndef CHSDAO_H
#define CHSDAO_H
#include"MyTableModel.h"
class ChsDao
{
public:
    bool addchsdao(int student_id,int course_id,int score);
    virtual bool deletechsdao(int id);
    virtual MyTableModel& querychsbyid(int studentid);
    virtual MyTableModel&  queryalldao();
};

#endif // CHSDAO_H
