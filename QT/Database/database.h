#ifndef DATABASE_H
#define DATABASE_H

#include <QMainWindow>

namespace Ui {
class Database;
}

class QStandardItemModel;

class Database : public QMainWindow
{
    Q_OBJECT

public:
    explicit Database(QWidget *parent = nullptr);
    ~Database();

private slots:
    void on_pushButton_clicked();

private:
    //void setValueAt(int x,int y)
    Ui::Database *ui;
    QStandardItemModel *mModel;
};

#endif // DATABASE_H
