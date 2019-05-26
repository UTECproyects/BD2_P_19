#include "database.h"
#include "ui_database.h"
#include <QStandardItemModel>
#include <QFileDialog>
#include <QTextStream>
#include <QFile>

Database::Database(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Database)
{
    ui->setupUi(this);
    mModel = new QStandardItemModel(this);
    ui->tableView->setModel(mModel);
    setCentralWidget(ui->tableView);

}

Database::~Database()
{
    delete ui;
}

void Database::on_pushButton_clicked()
{

}