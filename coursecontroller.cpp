#include "coursecontroller.h"
bool CourseController::addcourse(std::string coursename,int credits)
{
    return dao.addcoursedao(coursename,credits);
}
bool CourseController::deletecourse(int id)
{
    return dao.deletecoursedao(id);
}
MyTableModel& CourseController::querycoursebyid(int id)
{
    return dao.querycoursebyid(id);
}
MyTableModel& CourseController::querycoursebyname(std::string name)
{
    return dao.querycoursebyname(name);
}
MyTableModel& CourseController::queryall()
{
    return dao.queryalldao();
}
