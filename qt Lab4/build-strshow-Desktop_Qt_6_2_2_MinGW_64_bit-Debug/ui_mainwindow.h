/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableView *tableView_3;
    QTableView *tableView_2;
    QTableView *tableView;
    QTableView *tableView_5;
    QTableView *tableView_4;
    QTextEdit *textEdit;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_array;
    QLabel *label_struct;
    QLabel *label_class;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(901, 552);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableView_3 = new QTableView(centralwidget);
        tableView_3->setObjectName(QString::fromUtf8("tableView_3"));
        tableView_3->setGeometry(QRect(610, 0, 261, 131));
        tableView_3->horizontalHeader()->setVisible(true);
        tableView_3->horizontalHeader()->setCascadingSectionResizes(false);
        tableView_3->horizontalHeader()->setDefaultSectionSize(124);
        tableView_3->verticalHeader()->setCascadingSectionResizes(false);
        tableView_3->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableView_2 = new QTableView(centralwidget);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));
        tableView_2->setGeometry(QRect(340, 140, 261, 151));
        tableView_2->horizontalHeader()->setVisible(true);
        tableView_2->horizontalHeader()->setCascadingSectionResizes(false);
        tableView_2->horizontalHeader()->setDefaultSectionSize(420);
        tableView_2->verticalHeader()->setCascadingSectionResizes(false);
        tableView_2->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(340, 0, 261, 131));
        tableView->horizontalHeader()->setDefaultSectionSize(139);
        tableView_5 = new QTableView(centralwidget);
        tableView_5->setObjectName(QString::fromUtf8("tableView_5"));
        tableView_5->setGeometry(QRect(340, 300, 531, 111));
        tableView_5->horizontalHeader()->setVisible(true);
        tableView_5->horizontalHeader()->setCascadingSectionResizes(false);
        tableView_5->horizontalHeader()->setDefaultSectionSize(249);
        tableView_5->verticalHeader()->setCascadingSectionResizes(false);
        tableView_5->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableView_4 = new QTableView(centralwidget);
        tableView_4->setObjectName(QString::fromUtf8("tableView_4"));
        tableView_4->setGeometry(QRect(610, 140, 261, 151));
        tableView_4->horizontalHeader()->setVisible(true);
        tableView_4->horizontalHeader()->setCascadingSectionResizes(false);
        tableView_4->horizontalHeader()->setDefaultSectionSize(200);
        tableView_4->verticalHeader()->setCascadingSectionResizes(false);
        tableView_4->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 0, 321, 411));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 420, 314, 69));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_array = new QLabel(widget);
        label_array->setObjectName(QString::fromUtf8("label_array"));

        horizontalLayout->addWidget(label_array);

        label_struct = new QLabel(widget);
        label_struct->setObjectName(QString::fromUtf8("label_struct"));

        horizontalLayout->addWidget(label_struct);

        label_class = new QLabel(widget);
        label_class->setObjectName(QString::fromUtf8("label_class"));

        horizontalLayout->addWidget(label_class);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_2->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_2->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 901, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_array->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">\320\234\320\260\321\201\321\201\320\270\320\262\320\276\320\262 0</span></p></body></html>", nullptr));
        label_struct->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">\320\241\321\202\321\200\321\203\320\272\321\202\321\203\321\200 0</span></p></body></html>", nullptr));
        label_class->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">\320\232\320\273\320\260\321\201\321\201\320\276\320\262 0</span></p></body></html>", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\262\320\265\321\200\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
