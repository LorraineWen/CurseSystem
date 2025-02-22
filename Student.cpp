#include"Student.h"
Student::Student()
{

}
Student::Student(int id,std::string name,char gender,QDate birthday,std::string hometown,std::vector<std::string>classname,std::string majorname)
{
    this->id=id;
    this->name=name;
    this->gender=gender;
    this->birthday=birthday;
    this->hometown=hometown;
    this->majorname=majorname;
    this->classname=classname;
}
Student::~Student()
{

}
Student& Student::operator=(const Student& other)
{
    if(this==&other)
    {
        return *this;
    }
    this->id=other.id;
    this->name=other.name;
    this->classname=other.classname;
    this->majorname=other.majorname;
    this->gender=other.gender;
    this->hometown=other.hometown;
    this->birthday=other.birthday;
    return *this;
}
Student::Student(const Student& other)
{
    this->id=other.id;
    this->name=other.name;
    this->classname=other.classname;
    this->majorname=other.majorname;
    this->gender=other.gender;
    this->hometown=other.hometown;
    this->birthday=other.birthday;
}
