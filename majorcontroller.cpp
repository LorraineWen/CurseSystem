#include "majorcontroller.h"
bool MajorController::addmajor(std::string collegename,std::string majorname)
{
    return dao.addmajordao(collegename,majorname);
}
bool MajorController::deletemajor(int id)
{
    return dao.deletemajordao(id);
}
MyTableModel& MajorController::querymajorbyid(int id)
{
    return dao.querymajorbyid(id);
}
MyTableModel& MajorController::querymajorbyname(std::string name)
{
    return dao.querymajorbyname(name);
}
MyTableModel& MajorController::queryall()
{
    return dao.queryalldao();
}
