#ifndef STUDENT_H
#define STUDENT_H
#include<string>
#include<QDate>
class Student
{
public:
    Student();
    ~Student();
    Student(const Student& other);
    Student& operator=(const Student& other);
    Student(int id,std::string name,char gender,QDate birthday,std::string hometown,std::vector<std::string>classname,std::string majorname);
    int id;
    std::string name;
    char gender;
    QDate birthday;
    std::string hometown;
    std::vector<std::string>classname;
    std::string majorname;
};

#endif // STUDENT_H
