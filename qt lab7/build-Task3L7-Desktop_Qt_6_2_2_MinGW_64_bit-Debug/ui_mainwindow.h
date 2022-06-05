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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *CountButton;
    QSpinBox *Reset_One_spinBox;
    QSpinBox *set_oper_spinBox;
    QPushButton *ResetButton;
    QPushButton *SizeButton;
    QSpinBox *Set_spinBox;
    QLineEdit *StringLine;
    QLabel *none_label;
    QPushButton *AllButton;
    QPushButton *TestButton;
    QLineEdit *BitLine;
    QLabel *Test_label;
    QLabel *size_label;
    QLineEdit *ULongLine;
    QLabel *any_label;
    QPushButton *Flip_one_Button;
    QPushButton *SetOperButton;
    QSpinBox *set_value_spinBox;
    QPushButton *Flip_all_Button;
    QSpinBox *Test_spinBox;
    QPushButton *ResetOneButton;
    QPushButton *SetOneButton;
    QPushButton *SetAllButton;
    QPushButton *AnyButton;
    QLabel *all_label;
    QLabel *count_label;
    QSpinBox *Flip_spinBox;
    QPushButton *NoneButton;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        CountButton = new QPushButton(centralwidget);
        CountButton->setObjectName(QString::fromUtf8("CountButton"));
        CountButton->setGeometry(QRect(90, 220, 83, 31));
        CountButton->setStyleSheet(QString::fromUtf8(""));
        Reset_One_spinBox = new QSpinBox(centralwidget);
        Reset_One_spinBox->setObjectName(QString::fromUtf8("Reset_One_spinBox"));
        Reset_One_spinBox->setGeometry(QRect(670, 220, 51, 21));
        Reset_One_spinBox->setStyleSheet(QString::fromUtf8(""));
        set_oper_spinBox = new QSpinBox(centralwidget);
        set_oper_spinBox->setObjectName(QString::fromUtf8("set_oper_spinBox"));
        set_oper_spinBox->setGeometry(QRect(190, 390, 51, 21));
        set_oper_spinBox->setStyleSheet(QString::fromUtf8(""));
        ResetButton = new QPushButton(centralwidget);
        ResetButton->setObjectName(QString::fromUtf8("ResetButton"));
        ResetButton->setGeometry(QRect(570, 170, 83, 31));
        ResetButton->setStyleSheet(QString::fromUtf8(""));
        SizeButton = new QPushButton(centralwidget);
        SizeButton->setObjectName(QString::fromUtf8("SizeButton"));
        SizeButton->setGeometry(QRect(570, 330, 83, 31));
        SizeButton->setStyleSheet(QString::fromUtf8(""));
        Set_spinBox = new QSpinBox(centralwidget);
        Set_spinBox->setObjectName(QString::fromUtf8("Set_spinBox"));
        Set_spinBox->setGeometry(QRect(670, 300, 51, 21));
        Set_spinBox->setStyleSheet(QString::fromUtf8(""));
        StringLine = new QLineEdit(centralwidget);
        StringLine->setObjectName(QString::fromUtf8("StringLine"));
        StringLine->setGeometry(QRect(470, 100, 231, 28));
        StringLine->setReadOnly(true);
        none_label = new QLabel(centralwidget);
        none_label->setObjectName(QString::fromUtf8("none_label"));
        none_label->setGeometry(QRect(190, 340, 41, 31));
        none_label->setStyleSheet(QString::fromUtf8(""));
        AllButton = new QPushButton(centralwidget);
        AllButton->setObjectName(QString::fromUtf8("AllButton"));
        AllButton->setGeometry(QRect(90, 140, 83, 31));
        AllButton->setStyleSheet(QString::fromUtf8(""));
        TestButton = new QPushButton(centralwidget);
        TestButton->setObjectName(QString::fromUtf8("TestButton"));
        TestButton->setGeometry(QRect(570, 370, 83, 31));
        TestButton->setStyleSheet(QString::fromUtf8(""));
        BitLine = new QLineEdit(centralwidget);
        BitLine->setObjectName(QString::fromUtf8("BitLine"));
        BitLine->setGeometry(QRect(90, 100, 221, 28));
        BitLine->setReadOnly(true);
        Test_label = new QLabel(centralwidget);
        Test_label->setObjectName(QString::fromUtf8("Test_label"));
        Test_label->setGeometry(QRect(740, 370, 41, 31));
        Test_label->setStyleSheet(QString::fromUtf8(""));
        size_label = new QLabel(centralwidget);
        size_label->setObjectName(QString::fromUtf8("size_label"));
        size_label->setGeometry(QRect(670, 330, 41, 31));
        size_label->setStyleSheet(QString::fromUtf8(""));
        ULongLine = new QLineEdit(centralwidget);
        ULongLine->setObjectName(QString::fromUtf8("ULongLine"));
        ULongLine->setGeometry(QRect(340, 100, 121, 28));
        ULongLine->setReadOnly(true);
        any_label = new QLabel(centralwidget);
        any_label->setObjectName(QString::fromUtf8("any_label"));
        any_label->setGeometry(QRect(190, 180, 41, 31));
        any_label->setStyleSheet(QString::fromUtf8(""));
        Flip_one_Button = new QPushButton(centralwidget);
        Flip_one_Button->setObjectName(QString::fromUtf8("Flip_one_Button"));
        Flip_one_Button->setGeometry(QRect(90, 300, 83, 31));
        Flip_one_Button->setStyleSheet(QString::fromUtf8(""));
        SetOperButton = new QPushButton(centralwidget);
        SetOperButton->setObjectName(QString::fromUtf8("SetOperButton"));
        SetOperButton->setGeometry(QRect(90, 380, 83, 31));
        SetOperButton->setStyleSheet(QString::fromUtf8(""));
        set_value_spinBox = new QSpinBox(centralwidget);
        set_value_spinBox->setObjectName(QString::fromUtf8("set_value_spinBox"));
        set_value_spinBox->setGeometry(QRect(260, 390, 51, 21));
        set_value_spinBox->setStyleSheet(QString::fromUtf8(""));
        Flip_all_Button = new QPushButton(centralwidget);
        Flip_all_Button->setObjectName(QString::fromUtf8("Flip_all_Button"));
        Flip_all_Button->setGeometry(QRect(90, 260, 83, 31));
        Flip_all_Button->setStyleSheet(QString::fromUtf8(""));
        Test_spinBox = new QSpinBox(centralwidget);
        Test_spinBox->setObjectName(QString::fromUtf8("Test_spinBox"));
        Test_spinBox->setGeometry(QRect(670, 380, 51, 21));
        Test_spinBox->setStyleSheet(QString::fromUtf8(""));
        ResetOneButton = new QPushButton(centralwidget);
        ResetOneButton->setObjectName(QString::fromUtf8("ResetOneButton"));
        ResetOneButton->setGeometry(QRect(570, 210, 83, 31));
        ResetOneButton->setStyleSheet(QString::fromUtf8(""));
        SetOneButton = new QPushButton(centralwidget);
        SetOneButton->setObjectName(QString::fromUtf8("SetOneButton"));
        SetOneButton->setGeometry(QRect(570, 290, 83, 31));
        SetOneButton->setStyleSheet(QString::fromUtf8(""));
        SetAllButton = new QPushButton(centralwidget);
        SetAllButton->setObjectName(QString::fromUtf8("SetAllButton"));
        SetAllButton->setGeometry(QRect(570, 250, 83, 31));
        SetAllButton->setStyleSheet(QString::fromUtf8(""));
        AnyButton = new QPushButton(centralwidget);
        AnyButton->setObjectName(QString::fromUtf8("AnyButton"));
        AnyButton->setGeometry(QRect(90, 180, 83, 31));
        AnyButton->setStyleSheet(QString::fromUtf8(""));
        all_label = new QLabel(centralwidget);
        all_label->setObjectName(QString::fromUtf8("all_label"));
        all_label->setGeometry(QRect(190, 140, 41, 31));
        all_label->setStyleSheet(QString::fromUtf8(""));
        count_label = new QLabel(centralwidget);
        count_label->setObjectName(QString::fromUtf8("count_label"));
        count_label->setGeometry(QRect(190, 220, 41, 31));
        count_label->setStyleSheet(QString::fromUtf8(""));
        Flip_spinBox = new QSpinBox(centralwidget);
        Flip_spinBox->setObjectName(QString::fromUtf8("Flip_spinBox"));
        Flip_spinBox->setGeometry(QRect(190, 310, 51, 21));
        Flip_spinBox->setStyleSheet(QString::fromUtf8(""));
        NoneButton = new QPushButton(centralwidget);
        NoneButton->setObjectName(QString::fromUtf8("NoneButton"));
        NoneButton->setGeometry(QRect(90, 340, 83, 31));
        NoneButton->setStyleSheet(QString::fromUtf8(""));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(170, 70, 81, 20));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(360, 70, 91, 20));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(550, 70, 81, 20));
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
        CountButton->setText(QCoreApplication::translate("MainWindow", "Count", nullptr));
        ResetButton->setText(QCoreApplication::translate("MainWindow", "Res", nullptr));
        SizeButton->setText(QCoreApplication::translate("MainWindow", "Size", nullptr));
        none_label->setText(QString());
        AllButton->setText(QCoreApplication::translate("MainWindow", "All", nullptr));
        TestButton->setText(QCoreApplication::translate("MainWindow", "Test", nullptr));
        Test_label->setText(QString());
        size_label->setText(QString());
        any_label->setText(QString());
        Flip_one_Button->setText(QCoreApplication::translate("MainWindow", "Flip one", nullptr));
        SetOperButton->setText(QCoreApplication::translate("MainWindow", "Set ", nullptr));
        Flip_all_Button->setText(QCoreApplication::translate("MainWindow", "Flip all", nullptr));
        ResetOneButton->setText(QCoreApplication::translate("MainWindow", "Res one", nullptr));
        SetOneButton->setText(QCoreApplication::translate("MainWindow", "Set one", nullptr));
        SetAllButton->setText(QCoreApplication::translate("MainWindow", "Set all", nullptr));
        AnyButton->setText(QCoreApplication::translate("MainWindow", "Any", nullptr));
        all_label->setText(QString());
        count_label->setText(QString());
        NoneButton->setText(QCoreApplication::translate("MainWindow", "None", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\221\320\270\320\275\320\260\321\200\320\275\320\276\320\265", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\320\224\320\265\321\201\321\217\321\202\320\270\321\207\320\275\320\276\320\265", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\321\200\320\276\320\272\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
