#ifndef MYSQLUTILS_H
#define MYSQLUTILS_H
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlError>
#include<QtSql/QSqlQuery>
class MySqlUtils
{
private:
    MySqlUtils();
    MySqlUtils(const MySqlUtils& other)=delete;
    MySqlUtils& operator=(const MySqlUtils& other)=delete;
    static MySqlUtils utils;
    static QSqlDatabase db;
public:
    ~MySqlUtils();
    static MySqlUtils* get_instance();
    static QSqlDatabase get_db();
    void init();
};
#endif // MYSQLUTILS_H
