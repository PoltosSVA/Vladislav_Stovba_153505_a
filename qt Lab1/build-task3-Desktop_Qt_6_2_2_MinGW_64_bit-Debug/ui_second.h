/********************************************************************************
** Form generated from reading UI file 'second.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECOND_H
#define UI_SECOND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Second
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Second)
    {
        if (Second->objectName().isEmpty())
            Second->setObjectName(QString::fromUtf8("Second"));
        Second->resize(393, 277);
        centralwidget = new QWidget(Second);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 60, 231, 101));
        label->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Segoe UI\";"));
        Second->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Second);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 393, 26));
        Second->setMenuBar(menubar);
        statusbar = new QStatusBar(Second);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Second->setStatusBar(statusbar);

        retranslateUi(Second);

        QMetaObject::connectSlotsByName(Second);
    } // setupUi

    void retranslateUi(QMainWindow *Second)
    {
        Second->setWindowTitle(QCoreApplication::translate("Second", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("Second", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Second: public Ui_Second {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECOND_H
