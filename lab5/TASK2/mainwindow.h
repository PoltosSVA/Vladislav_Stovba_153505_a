#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Deque.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    deque<int> Ojb;
    int rSize=0;
    QString text;
    QString vs9;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
