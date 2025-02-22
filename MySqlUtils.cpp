#include"MySqlUtils.h"
#include<iostream>
MySqlUtils MySqlUtils::utils;
QSqlDatabase MySqlUtils::db;
MySqlUtils* MySqlUtils::get_instance()
{
    return &utils;
}
MySqlUtils::~MySqlUtils()
{
    db.close();
    if (!db.isOpen())
    {
        std::cerr << "Database connection successfully closed." << std::endl;
    } else
    {
        std::cerr << "Failed to close database connection." << std::endl;
    }
}
MySqlUtils::MySqlUtils()
{

}
void MySqlUtils::init()
{
    db=QSqlDatabase::addDatabase("QODBC");
    db.setHostName("localhost");
    db.setPort(3306);
    db.setDatabaseName("coursesystem");
    db.setUserName("root");
    db.setPassword("kylin.2023");
    if (!db.open())
    {
        std::cerr << "Error: Unable to connect to database!" << std::endl;
        std::cerr << db.lastError().text().toUtf8().constData() << std::endl;
    }
    std::cout << "Database connected successfully!" << std::endl;
}
QSqlDatabase MySqlUtils::get_db()
{
    return db;
}
