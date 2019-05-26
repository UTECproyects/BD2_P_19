/********************************************************************************
** Form generated from reading UI file 'database.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATABASE_H
#define UI_DATABASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Database
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QSplitter *splitter_2;
    QSplitter *splitter;
    QListView *listView;
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QTableView *tableView;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Database)
    {
        if (Database->objectName().isEmpty())
            Database->setObjectName(QString::fromUtf8("Database"));
        Database->resize(677, 386);
        centralWidget = new QWidget(Database);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        splitter_2 = new QSplitter(centralWidget);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setMinimumSize(QSize(0, 60));
        splitter->setMaximumSize(QSize(16777215, 190));
        splitter->setOrientation(Qt::Horizontal);
        listView = new QListView(splitter);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setMaximumSize(QSize(191, 190));
        splitter->addWidget(listView);
        textEdit = new QTextEdit(splitter);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setMaximumSize(QSize(16777215, 190));
        splitter->addWidget(textEdit);
        pushButton = new QPushButton(splitter);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMaximumSize(QSize(60, 190));
        splitter->addWidget(pushButton);
        splitter_2->addWidget(splitter);
        tableView = new QTableView(splitter_2);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        splitter_2->addWidget(tableView);

        verticalLayout->addWidget(splitter_2);

        Database->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Database);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 677, 20));
        Database->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Database);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Database->addToolBar(Qt::TopToolBarArea, mainToolBar);
        Database->insertToolBarBreak(mainToolBar);
        statusBar = new QStatusBar(Database);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Database->setStatusBar(statusBar);

        retranslateUi(Database);

        QMetaObject::connectSlotsByName(Database);
    } // setupUi

    void retranslateUi(QMainWindow *Database)
    {
        Database->setWindowTitle(QApplication::translate("Database", "Database", nullptr));
        pushButton->setText(QApplication::translate("Database", "enter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Database: public Ui_Database {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASE_H
