#ifndef TECDAO_H
#define TECDAO_H
#include"MyTableModel.h"
class MajorDao
{
public:
    bool addmajordao(std::string name,std::string major_name);
    virtual bool deletemajordao(int id);
    virtual MyTableModel& querymajorbyname(std::string name);
    virtual MyTableModel& querymajorbyid(int id);
    virtual MyTableModel&  queryalldao();
};

#endif // TECDAO_H
