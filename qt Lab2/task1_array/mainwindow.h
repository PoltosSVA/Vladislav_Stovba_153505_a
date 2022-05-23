#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QFileDialog>
#include <QRegularExpressionValidator>
#include <QMessageBox>
#include <regex>
#include "list.h"
#include "employe.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void File_Add();
    void refresh_table();
    void metodStandart();
    void FileDelete();
    void CheckVoid();
    void show_Error();
    void Range();
    QString return_name();


    QString return_ser_name();


    QString return_second_name();



    QRegularExpressionValidator name__;
    QRegularExpressionValidator sername__;
    QRegularExpressionValidator secondname__;
    QRegularExpressionValidator country__;
    QRegularExpressionValidator team__;
    QRegularExpressionValidator Rost__;
    QRegularExpressionValidator vse__;
    QRegularExpressionValidator age__;
    QRegularExpressionValidator reg_num__;
    QRegularExpressionValidator sername___;








    QString return_country();


    QString return_team();


    QString return_Rost();


    QString return_ves();

    QString return_reg_num();
    QString return_age();
    bool File_deff();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();



    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    int rSize =0;
    int MaxSize = 10000;
    ArrayList* SOREV;
    QStandardItemModel* table;
    QString str;
    int check_count=0;
    bool vosh = false;



};
#endif // MAINWINDOW_H
