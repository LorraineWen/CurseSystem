#include "chscontroller.h"

bool ChsController::addchs(int student_id,int course_id,int score)
{
    return dao.addchsdao(student_id,course_id,score);
}
bool ChsController::deletechs(int id)
{
    return dao.deletechsdao(id);
}
MyTableModel& ChsController::querychsbyid(int id)
{
    return dao.querychsbyid(id);
}
MyTableModel& ChsController::queryall()
{
    return dao.queryalldao();
}
