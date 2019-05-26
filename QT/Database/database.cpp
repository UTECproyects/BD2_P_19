#include "database.h"
#include "ui_database.h"
#include <QStandardItemModel>
#include <QFileDialog>
#include <QTextStream>
#include <QFile>
#ifndef QTapp_h
    #define QTapp_h  "../../"
#endif
#include "../../Dependencies/registros.h"

Database::Database(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Database)
{
    ui->setupUi(this);
    mModel = new QStandardItemModel(this);
    ui->tableView->setModel(mModel);
    //setCentralWidget(ui->tableView);

}

Database::~Database()
{
    delete ui;
}

void Database::on_pushButton_clicked()
{
    Registros reg;
    reg.get_registro(0);
    reg.print();
    std::string text = ui->textEdit->toPlainText().toUtf8().constData();


    mModel->setRowCount(1);
    mModel->setColumnCount(13);
    mModel->setItem(0,0,new QStandardItem(reg.App));
    mModel->setItem(0,1,new QStandardItem(reg.Category));
    mModel->setItem(0,2,new QStandardItem(std::to_string(reg.Rating).c_str()));
    mModel->setItem(0,3,new QStandardItem(std::to_string(reg.Review).c_str()));
    mModel->setItem(0,4,new QStandardItem(reg.Size));
    mModel->setItem(0,5,new QStandardItem(reg.Installs));
    mModel->setItem(0,6,new QStandardItem(reg.Type));
    mModel->setItem(0,7,new QStandardItem(reg.Price));
    mModel->setItem(0,8,new QStandardItem(reg.Content_Rating));
    mModel->setItem(0,9,new QStandardItem(reg.Genres));
    mModel->setItem(0,10,new QStandardItem(reg.Last_Updates));
    mModel->setItem(0,11,new QStandardItem(reg.Current_Ver));
    mModel->setItem(0,12,new QStandardItem(reg.Android_Ver));
}
