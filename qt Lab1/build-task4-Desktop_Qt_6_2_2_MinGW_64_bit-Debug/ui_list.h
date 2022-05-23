/********************************************************************************
** Form generated from reading UI file 'list.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIST_H
#define UI_LIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_List
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_5;
    QVBoxLayout *verticalLayout;
    QLineEdit *Second;
    QLineEdit *sername;
    QLineEdit *Name;
    QLineEdit *NAZV;
    QLineEdit *IZD;
    QSpinBox *Stran;
    QSpinBox *Date;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *List)
    {
        if (List->objectName().isEmpty())
            List->setObjectName(QString::fromUtf8("List"));
        List->resize(379, 348);
        centralwidget = new QWidget(List);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 20, 304, 273));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Segoe UI\";"));

        verticalLayout_2->addWidget(label_3);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Segoe UI\";"));

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Segoe UI\";"));

        verticalLayout_2->addWidget(label_2);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Segoe UI\";"));

        verticalLayout_2->addWidget(label_4);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Segoe UI\";"));

        verticalLayout_2->addWidget(label_6);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Segoe UI\";"));

        verticalLayout_2->addWidget(label_7);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Segoe UI\";"));

        verticalLayout_2->addWidget(label_5);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        Second = new QLineEdit(layoutWidget);
        Second->setObjectName(QString::fromUtf8("Second"));

        verticalLayout->addWidget(Second);

        sername = new QLineEdit(layoutWidget);
        sername->setObjectName(QString::fromUtf8("sername"));

        verticalLayout->addWidget(sername);

        Name = new QLineEdit(layoutWidget);
        Name->setObjectName(QString::fromUtf8("Name"));

        verticalLayout->addWidget(Name);

        NAZV = new QLineEdit(layoutWidget);
        NAZV->setObjectName(QString::fromUtf8("NAZV"));

        verticalLayout->addWidget(NAZV);

        IZD = new QLineEdit(layoutWidget);
        IZD->setObjectName(QString::fromUtf8("IZD"));

        verticalLayout->addWidget(IZD);

        Stran = new QSpinBox(layoutWidget);
        Stran->setObjectName(QString::fromUtf8("Stran"));
        Stran->setMinimum(1);
        Stran->setMaximum(1500);

        verticalLayout->addWidget(Stran);

        Date = new QSpinBox(layoutWidget);
        Date->setObjectName(QString::fromUtf8("Date"));
        Date->setMinimum(1564);
        Date->setMaximum(2022);

        verticalLayout->addWidget(Date);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_3->addWidget(pushButton);

        List->setCentralWidget(centralwidget);
        menubar = new QMenuBar(List);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 379, 26));
        List->setMenuBar(menubar);
        statusbar = new QStatusBar(List);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        List->setStatusBar(statusbar);

        retranslateUi(List);

        QMetaObject::connectSlotsByName(List);
    } // setupUi

    void retranslateUi(QMainWindow *List)
    {
        List->setWindowTitle(QCoreApplication::translate("List", "MainWindow", nullptr));
        label_3->setText(QCoreApplication::translate("List", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        label->setText(QCoreApplication::translate("List", "\320\230\320\274\321\217", nullptr));
        label_2->setText(QCoreApplication::translate("List", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        label_4->setText(QCoreApplication::translate("List", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        label_6->setText(QCoreApplication::translate("List", "\320\230\320\267\320\264\320\260\321\202\320\265\320\273\321\214\321\201\321\202\320\262\320\276", nullptr));
        label_7->setText(QCoreApplication::translate("List", "\320\241\321\202\320\260\320\275\320\270\321\206\321\213", nullptr));
        label_5->setText(QCoreApplication::translate("List", "\320\223\320\276\320\264 \320\270\320\267\320\264\320\260\320\275\320\270\321\217", nullptr));
        pushButton->setText(QCoreApplication::translate("List", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class List: public Ui_List {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIST_H
