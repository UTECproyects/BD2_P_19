#ifndef DATABASE_H
#define DATABASE_H

#include <QMainWindow>

namespace Ui {
class Database;
}

class QstandardItemModel;

class Database : public QMainWindow
{
    Q_OBJECT

public:
    explicit Database(QWidget *parent = nullptr);
    ~Database();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Database *ui;
    QstandardItemModel *mModel;
};

#endif // DATABASE_H
