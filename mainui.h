#ifndef MAINUI_H
#define MAINUI_H
#include"StuController.h"
#include "stutablebutton.h"
#include"addstudentui.h"
#include"addcourseui.h"
#include"majorcontroller.h"
#include"coursecontroller.h"
#include"addmajorui.h"
#include"addchsui.h"
#include"chscontroller.h"
#include <QFrame>
#include<QTableView>
namespace Ui {
class MainUi;
}

class MainUi : public QFrame
{
    Q_OBJECT

public:
    explicit MainUi(QWidget *parent = nullptr);
    ~MainUi();

private slots:
    void on_addstubutton_clicked();
    void on_addtecbutton_clicked();
    void on_addcousebutton_clicked();
    void on_stumanagebutton_clicked();
    void onDeleteStuButtonClicked(const QModelIndex& row);
    void onDeleteMajorButtonClicked(const QModelIndex& row);
    void onDeleteCourseButtonClicked(const QModelIndex& row);
    void onDeleteScoreButtonClicked(const QModelIndex& row);
    void onDeleteChsButtonClicked(const QModelIndex& row);
    void on_querystubutton_clicked();
    void updateTableView(QAbstractTableModel* model,QTableView* table,StuTableButton*delegate);
    void on_tecmanagebutton_clicked();
    void on_querytecbutton_clicked();
    void on_coursemanagebutton_clicked();
    void on_exitbutton_clicked();
    void on_querycoursebutton_clicked();
    void on_chsmanagebutton_clicked();

    void on_addchsbutton_clicked();

    void on_querychsbutton_clicked();

    void on_scoremanagebutton_clicked();

    void on_queryscorebutton_clicked();

    void on_querystuscorebutton_clicked();

    void on_querystubutton_5_clicked();

    void on_querystuscorebutton_3_clicked();

    void on_addstubutton_3_clicked();

private:
    Ui::MainUi *ui;
    StuController stucontroller;
    MajorController majorcontroller;
    CourseController coursecontroller;
    ChsController chscontroller;
    QSqlTableModel* stumodel;
    QSqlTableModel* majormodel;
    QSqlTableModel* coursemodel;
    QSqlTableModel* chsmodel;
    QSqlTableModel* scoremodel;
    QSqlQueryModel* totalscoremodel;
    StuTableButton* delegate;
    AddStudentUi addstuui;
    AddMajorUi addmajorui;
    AddCourseUi addcourseui;
    AddChsUi addchsui;
};

#endif // MAINUI_H
