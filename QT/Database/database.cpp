#include "database.h"
#include "ui_database.h"
#include <QStandardItemModel>
#include <QFileDialog>
#include <QTextStream>
#include <QFile>


#define QTapp_h  "../../"
#include "../../DynamicHashing/dynamicHashing.h"
#include "../../Random_File/Querys/query.h"


Database::Database(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Database)
{
    ui->setupUi(this);
    mModel = new QStandardItemModel(this);
    ui->tableView->setModel(mModel);
    ui->textEdit->setDocumentTitle("Buscar aplicacion: ");
    Registros regs;
    int sizeDocument = regs.getDocumentSize();
    for(int i = 0; i < sizeDocument; i++){
      regs.get_registro(i);
      string app(regs.App);
      insertToTable(regs.App,i);
    }
    //setCentralWidget(ui->tableView);

}

Database::~Database()
{
    delete ui;
}

void Database::on_pushButton_clicked()
{

    std::string text = ui->textEdit->toPlainText().toUtf8().constData();
    if(text=="all"){
        Databases dd("gg");
        vector<Registros*>registros=dd.get_all();
        mModel->setRowCount(registros[1]->getDocumentSize());
        mModel->setColumnCount(13);
        for(int i=0;i<registros.size();i++){
            mModel->setItem(i,0,new QStandardItem(registros[i]->App));
            mModel->setItem(i,1,new QStandardItem(registros[i]->Category));
            mModel->setItem(i,2,new QStandardItem(std::to_string(registros[i]->Rating).c_str()));
            mModel->setItem(i,3,new QStandardItem(std::to_string(registros[i]->Review).c_str()));
            mModel->setItem(i,4,new QStandardItem(registros[i]->Size));
            mModel->setItem(i,5,new QStandardItem(registros[i]->Installs));
            mModel->setItem(i,6,new QStandardItem(registros[i]->Type));
            mModel->setItem(i,7,new QStandardItem(registros[i]->Price));
            mModel->setItem(i,8,new QStandardItem(registros[i]->Content_Rating));
            mModel->setItem(i,9,new QStandardItem(registros[i]->Genres));
            mModel->setItem(i,10,new QStandardItem(registros[i]->Last_Updates));
            mModel->setItem(i,11,new QStandardItem(registros[i]->Current_Ver));
            mModel->setItem(i,12,new QStandardItem(registros[i]->Android_Ver));
        }
        return;
    }
    Registros* reg= new Registros;
    //query obj;
    //auto bk=obj.ejecutar_consulta_recibida(text);
    //reg=bk.first;

    reg = searchInTable(text);
    if(reg==NULL){
        mModel->setRowCount(1);
        mModel->setColumnCount(1);
        mModel->setItem(0,0,new QStandardItem("No se encontro"));
        return;
    }

    mModel->setRowCount(1);
    mModel->setColumnCount(13);
    mModel->setItem(0,0,new QStandardItem(reg->App));
    mModel->setItem(0,1,new QStandardItem(reg->Category));
    mModel->setItem(0,2,new QStandardItem(std::to_string(reg->Rating).c_str()));
    mModel->setItem(0,3,new QStandardItem(std::to_string(reg->Review).c_str()));
    mModel->setItem(0,4,new QStandardItem(reg->Size));
    mModel->setItem(0,5,new QStandardItem(reg->Installs));
    mModel->setItem(0,6,new QStandardItem(reg->Type));
    mModel->setItem(0,7,new QStandardItem(reg->Price));
    mModel->setItem(0,8,new QStandardItem(reg->Content_Rating));
    mModel->setItem(0,9,new QStandardItem(reg->Genres));
    mModel->setItem(0,10,new QStandardItem(reg->Last_Updates));
    mModel->setItem(0,11,new QStandardItem(reg->Current_Ver));
    mModel->setItem(0,12,new QStandardItem(reg->Android_Ver));
    delete reg;
}
