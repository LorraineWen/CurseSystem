#ifndef COURSEDAO_H
#define COURSEDAO_H
#include<string>
#include"MyTableModel.h"
class CourseDao
{
public:
    bool addcoursedao(std::string name,int credit);
    virtual bool deletecoursedao(int id);
    virtual MyTableModel& querycoursebyname(std::string name);
    virtual MyTableModel& querycoursebyid(int id);
    virtual MyTableModel&  queryalldao();
};

#endif // COURSEDAO_H
