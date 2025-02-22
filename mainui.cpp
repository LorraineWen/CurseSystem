#include "mainui.h"
#include "ui_mainui.h"
#include<QMessageBox>
MainUi::MainUi(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::MainUi)
{
    ui->setupUi(this);
}

MainUi::~MainUi()
{
}

void MainUi::on_addstubutton_clicked()
{
    connect(&addstuui, &AddStudentUi::studentAdded, this, &MainUi::on_stumanagebutton_clicked);
    addstuui.show();
}
void MainUi::on_addtecbutton_clicked()
{
    connect(&addmajorui, &AddMajorUi::majorAdded, this, &MainUi::on_tecmanagebutton_clicked);
    addmajorui.show();
}
void MainUi::on_addcousebutton_clicked()
{
    connect(&addcourseui, &AddCourseUi::courseAdded, this, &MainUi::on_coursemanagebutton_clicked);
    addcourseui.show();
}
void MainUi::on_addchsbutton_clicked()
{
    connect(&addchsui, &AddChsUi::chsAdded, this, &MainUi::on_chsmanagebutton_clicked);
    addchsui.show();
}
void MainUi::on_exitbutton_clicked()
{
    this->~MainUi();
    exit(0);
}
void MainUi::on_stumanagebutton_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(0);
    stumodel = &stucontroller.queryall();
    delegate = new StuTableButton(this);
    connect(delegate, &StuTableButton::deleteButtonClicked, this, &MainUi::onDeleteStuButtonClicked);
    updateTableView(stumodel,this->ui->stutable,delegate);
}

void MainUi::on_tecmanagebutton_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(1);
    majormodel = &majorcontroller.queryall();
    delegate = new StuTableButton(this);
    connect(delegate, &StuTableButton::deleteButtonClicked, this, &MainUi::onDeleteMajorButtonClicked);
    updateTableView(majormodel,this->ui->tectable,delegate);
}

void MainUi::on_scoremanagebutton_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(4);
    scoremodel = &stucontroller.queryallscore();
    this->ui->scoretable->reset();
    this->ui->scoretable->setModel(scoremodel);
    this->ui->scoretable->setMouseTracking(true);
    this->ui->scoretable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    int columnCount = scoremodel->columnCount();
    for (int i = 0; i < columnCount; ++i)
    {
        if (i == 4 || i == 5)
        {
            this->ui->scoretable->horizontalHeader()->setSectionResizeMode(i, QHeaderView::ResizeToContents);
        } else
        {
            this->ui->scoretable->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
        }
    }
    this->ui->scoretable->verticalHeader()->setVisible(false);
    this->ui->scoretable->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::EditKeyPressed);
}
void MainUi::updateTableView(QAbstractTableModel* model,QTableView* table,StuTableButton* delegate)
{
    table->reset();
    table->setModel(model);
    table->setMouseTracking(true);
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    int columnCount = model->columnCount();
    for (int i = 0; i < columnCount; ++i)
    {
        if (i == 4 || i == 5)
        {
            table->horizontalHeader()->setSectionResizeMode(i, QHeaderView::ResizeToContents);
        } else
        {
            table->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
        }
    }
    table->verticalHeader()->setVisible(false);
    table->setItemDelegate(delegate);
    table->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::EditKeyPressed);
}

void MainUi::onDeleteStuButtonClicked(const QModelIndex& index)
{
    // 获取与当前行对应的第一列数据（即学生ID）
    QModelIndex firstColumnIndex = index.sibling(index.row(), 0);  // 获取同一行的第一列
    int studentId = firstColumnIndex.data().toInt();  // 获取第一列数据并转换为整数

    if (stucontroller.deletestudent(studentId))
    {
        QMessageBox::information(this, "Success", "Student information deleted");
        stumodel = &stucontroller.queryall();
        this->ui->stutable->setModel(stumodel);
    }
    else
    {
        QMessageBox::warning(this, "Failed", "Deleted Failed");
    }
}
void MainUi::onDeleteMajorButtonClicked(const QModelIndex& index)
{
    QModelIndex firstColumnIndex = index.sibling(index.row(), 0);
    int id = firstColumnIndex.data().toInt();
    if (majorcontroller.deletemajor(id))
    {
        QMessageBox::information(this, "Success", "Major information deleted");
        majormodel = &majorcontroller.queryall();
        this->ui->tectable->setModel(majormodel);
    }
    else
    {
        QMessageBox::warning(this, "Failed", "Deleted Failed");
    }
}
void MainUi::onDeleteCourseButtonClicked(const QModelIndex& index)
{
    QModelIndex firstColumnIndex = index.sibling(index.row(), 0);
    int id = firstColumnIndex.data().toInt();
    if (coursecontroller.deletecourse(id))
    {
        QMessageBox::information(this, "Success", "Course information deleted");
        coursemodel = &coursecontroller.queryall();
        this->ui->coursetable->setModel(coursemodel);
    }
    else
    {
        QMessageBox::warning(this, "Failed", "Deleted Failed");
    }
}
void MainUi::onDeleteScoreButtonClicked(const QModelIndex& index)
{
    QModelIndex firstColumnIndex = index.sibling(index.row(), 0);
    int id = firstColumnIndex.data().toInt();
    if (stucontroller.deletescore(id))
    {
        QMessageBox::information(this, "Success", "Score information deleted");
        scoremodel = &stucontroller.queryallscore();
        this->ui->scoretable->setModel(scoremodel);
    }
    else
    {
        QMessageBox::warning(this, "Failed", "Deleted Failed");
    }
}
void MainUi::onDeleteChsButtonClicked(const QModelIndex& index)
{
    QModelIndex firstColumnIndex = index.sibling(index.row(), 0);
    int id = firstColumnIndex.data().toInt();
    if (chscontroller.deletechs(id))
    {
        QMessageBox::information(this, "Success", "Chs information deleted");
        chsmodel = &chscontroller.queryall();
        this->ui->chstable->setModel(chsmodel);
    }
    else
    {
        QMessageBox::warning(this, "Failed", "Deleted Failed");
    }
}
void MainUi::on_querystubutton_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(0);
    QString nameorid=this->ui->stunameorid->toPlainText();
    stumodel=&stucontroller.querystudentbyname(nameorid.toStdString());
    if(stumodel->rowCount()==0)
    {
        stumodel=&stucontroller.querystudentbyid(nameorid.toInt());
    }
    this->ui->stutable->setModel(stumodel);
    this->ui->stutable->setMouseTracking(true);
    ui->stutable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->stutable->horizontalHeader()->setSectionResizeMode(4,QHeaderView::ResizeToContents);
    ui->stutable->horizontalHeader()->setSectionResizeMode(5,QHeaderView::ResizeToContents);
    ui->stutable->verticalHeader()->setVisible(false);
    delegate = new StuTableButton(this);
    this->ui->stutable->setItemDelegate(delegate);
    this->ui->stutable->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::EditKeyPressed);
    connect(delegate, &StuTableButton::deleteButtonClicked, this, &MainUi::onDeleteStuButtonClicked);
}
void MainUi::on_querytecbutton_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(1);
    QString nameorid=this->ui->tecnameorid->toPlainText();
    majormodel=&majorcontroller.querymajorbyname(nameorid.toStdString());
    if(majormodel->rowCount()==0)
    {
        majormodel=&majorcontroller.querymajorbyid(nameorid.toInt());
    }
    delegate = new StuTableButton(this);
    connect(delegate, &StuTableButton::deleteButtonClicked, this, &MainUi::onDeleteMajorButtonClicked);
    updateTableView(majormodel,this->ui->tectable,delegate);
}
void MainUi::on_querycoursebutton_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(2);
    QString nameorid=this->ui->coursenameorid->toPlainText();
    coursemodel=&coursecontroller.querycoursebyname(nameorid.toStdString());
    if(coursemodel->rowCount()==0)
    {
        coursemodel=&coursecontroller.querycoursebyid(nameorid.toInt());
    }
    delegate = new StuTableButton(this);
    connect(delegate, &StuTableButton::deleteButtonClicked, this, &MainUi::onDeleteMajorButtonClicked);
    updateTableView(coursemodel,this->ui->coursetable,delegate);
}
void MainUi::on_querychsbutton_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(3);
    int id=this->ui->studentid->toPlainText().toInt();
    chsmodel=&chscontroller.querychsbyid(id);
    delegate = new StuTableButton(this);
    connect(delegate, &StuTableButton::deleteButtonClicked, this, &MainUi::onDeleteMajorButtonClicked);
    updateTableView(chsmodel,this->ui->chstable,delegate);
}
void MainUi::on_queryscorebutton_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(4);
    int id=this->ui->scoreid->toPlainText().toInt();
    scoremodel=&stucontroller.queryscorebyid(id);
    this->ui->scoretable->reset();
    this->ui->scoretable->setModel(scoremodel);
    this->ui->scoretable->setMouseTracking(true);
    this->ui->scoretable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    int columnCount = scoremodel->columnCount();
    for (int i = 0; i < columnCount; ++i)
    {
        if (i == 4 || i == 5)
        {
            this->ui->scoretable->horizontalHeader()->setSectionResizeMode(i, QHeaderView::ResizeToContents);
        } else
        {
            this->ui->scoretable->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
        }
    }
    this->ui->scoretable->verticalHeader()->setVisible(false);
    this->ui->scoretable->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::EditKeyPressed);
}
void MainUi::on_querystuscorebutton_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(5);
    int id = this->ui->courseid->toPlainText().toInt();
    totalscoremodel = &stucontroller.querystuscorebyid(id);
    this->ui->showscoretable->reset();
    this->ui->showscoretable->setModel(totalscoremodel);
    this->ui->showscoretable->setMouseTracking(true);
    this->ui->showscoretable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    int columnCount = totalscoremodel->columnCount();
    for (int i = 0; i < columnCount; ++i)
    {
        if (i == 4 || i == 5)
        {
            this->ui->showscoretable->horizontalHeader()->setSectionResizeMode(i, QHeaderView::ResizeToContents);
        }
        else
        {
            this->ui->showscoretable->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
        }
    }
    this->ui->showscoretable->verticalHeader()->setVisible(false);
    this->ui->showscoretable->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::EditKeyPressed);
}


void MainUi::on_coursemanagebutton_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(2);
    coursemodel = &coursecontroller.queryall();
    delegate = new StuTableButton(this);
    connect(delegate, &StuTableButton::deleteButtonClicked, this, &MainUi::onDeleteCourseButtonClicked);
    updateTableView(coursemodel,this->ui->coursetable,delegate);
}

void MainUi::on_chsmanagebutton_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(3);
    chsmodel = &chscontroller.queryall();
    delegate = new StuTableButton(this);
    connect(delegate, &StuTableButton::deleteButtonClicked, this, &MainUi::onDeleteChsButtonClicked);
    updateTableView(chsmodel,this->ui->chstable,delegate);
}


void MainUi::on_querystubutton_5_clicked()
{
    on_querystubutton_clicked();
}


void MainUi::on_querystuscorebutton_3_clicked()
{
    on_querystuscorebutton_clicked();
}


void MainUi::on_addstubutton_3_clicked()
{
    on_addstubutton_clicked();
}

