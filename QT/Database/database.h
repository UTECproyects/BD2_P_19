#ifndef DATABASE_H
#define DATABASE_H

#include <QMainWindow>

namespace Ui {
class Database;
}

<<<<<<< HEAD
class QstandardItemModel;
=======
class QStandardItemModel;
>>>>>>> 7c7d9ac57fab3e533c8bb1643841a1d7c5976173

class Database : public QMainWindow
{
    Q_OBJECT

public:
    explicit Database(QWidget *parent = nullptr);
    ~Database();

private slots:
    void on_pushButton_clicked();

private:
<<<<<<< HEAD
    Ui::Database *ui;
    QstandardItemModel *mModel;
=======
    //void setValueAt(int x,int y)
    Ui::Database *ui;
    QStandardItemModel *mModel;
>>>>>>> 7c7d9ac57fab3e533c8bb1643841a1d7c5976173
};

#endif // DATABASE_H
