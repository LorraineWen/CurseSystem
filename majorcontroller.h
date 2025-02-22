#ifndef MAJORCONTROLLER_H
#define MAJORCONTROLLER_H
#include"majordao.h"
class MajorController
{
public:
    bool addmajor(std::string collegename,std::string majorname);
    bool deletemajor(int id);
    MyTableModel& querymajorbyid(int id);
    MyTableModel& querymajorbyname(std::string name);
    MyTableModel& queryall();
private:
    MajorDao dao;
};

#endif // MAJORCONTROLLER_H
