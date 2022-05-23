/********************************************************************************
** Form generated from reading UI file 'canvas.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CANVAS_H
#define UI_CANVAS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_canvas
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *canvas)
    {
        if (canvas->objectName().isEmpty())
            canvas->setObjectName(QString::fromUtf8("canvas"));
        canvas->resize(800, 600);
        centralwidget = new QWidget(canvas);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(-5, 1, 791, 471));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(220, 490, 195, 31));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        canvas->setCentralWidget(centralwidget);
        menubar = new QMenuBar(canvas);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        canvas->setMenuBar(menubar);
        statusbar = new QStatusBar(canvas);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        canvas->setStatusBar(statusbar);

        retranslateUi(canvas);

        QMetaObject::connectSlotsByName(canvas);
    } // setupUi

    void retranslateUi(QMainWindow *canvas)
    {
        canvas->setWindowTitle(QCoreApplication::translate("canvas", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("canvas", "Clear", nullptr));
        pushButton_2->setText(QCoreApplication::translate("canvas", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class canvas: public Ui_canvas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CANVAS_H
