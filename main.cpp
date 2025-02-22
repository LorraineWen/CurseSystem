#include "mainui.h"
#include "MySqlUtils.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainUi w;
    MySqlUtils* utils=MySqlUtils::get_instance();
    utils->init();
    w.show();
    w.setWindowIcon(QIcon(":/programlogo.png"));
    w.setWindowTitle("吉首大学学生选课管理系统");
    return a.exec();
}
