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
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QTreeWidget *treeWidget;
    QTextEdit *textEdit;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinBox;
    QLabel *label_2;
    QSpinBox *spinBox_2;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QSpinBox *spinBox_3;
    QPushButton *pushButton_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QSpinBox *spinBox_4;
    QPushButton *pushButton_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_10;
    QSpinBox *spinBox_5;
    QPushButton *pushButton_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 0, 361, 421));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        treeWidget = new QTreeWidget(widget);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->header()->setMinimumSectionSize(150);
        treeWidget->header()->setDefaultSectionSize(170);

        verticalLayout->addWidget(treeWidget);

        textEdit = new QTextEdit(widget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout->addWidget(textEdit);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(390, 10, 325, 147));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget1);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        spinBox = new QSpinBox(widget1);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMinimum(-99);
        spinBox->setMaximum(99);

        horizontalLayout->addWidget(spinBox);

        label_2 = new QLabel(widget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        spinBox_2 = new QSpinBox(widget1);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setMinimum(-99);
        spinBox_2->setMaximum(99);

        horizontalLayout->addWidget(spinBox_2);

        pushButton = new QPushButton(widget1);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(widget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        spinBox_3 = new QSpinBox(widget1);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        spinBox_3->setMinimum(-99);
        spinBox_3->setMaximum(99);

        horizontalLayout_2->addWidget(spinBox_3);

        pushButton_2 = new QPushButton(widget1);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(widget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        spinBox_4 = new QSpinBox(widget1);
        spinBox_4->setObjectName(QString::fromUtf8("spinBox_4"));
        spinBox_4->setMinimum(-99);
        spinBox_4->setMaximum(99);

        horizontalLayout_3->addWidget(spinBox_4);

        pushButton_3 = new QPushButton(widget1);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_3->addWidget(pushButton_3);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_10 = new QLabel(widget1);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_4->addWidget(label_10);

        spinBox_5 = new QSpinBox(widget1);
        spinBox_5->setObjectName(QString::fromUtf8("spinBox_5"));
        spinBox_5->setMinimum(-99);
        spinBox_5->setMaximum(99);

        horizontalLayout_4->addWidget(spinBox_5);

        pushButton_4 = new QPushButton(widget1);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        horizontalLayout_4->addWidget(pushButton_4);


        verticalLayout_2->addLayout(horizontalLayout_4);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
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
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("MainWindow", "Value", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("MainWindow", "Key", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\232\320\273\321\216\321\207", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\232\320\273\321\216\321\207", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\232\320\273\321\216\321\207", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Find", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "I", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Value", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
