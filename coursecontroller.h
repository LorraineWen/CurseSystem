#ifndef COURSECONTROLLER_H
#define COURSECONTROLLER_H
#include"coursedao.h"
class CourseController
{
public:
    bool addcourse(std::string coursename,int credits);
    bool deletecourse(int id);
    MyTableModel& querycoursebyid(int id);
    MyTableModel& querycoursebyname(std::string name);
    MyTableModel& queryall();
private:
    CourseDao dao;
};

#endif // COURSECONTROLLER_H
