#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <iostream>
#include <QFileDialog>
#include <QRegularExpressionValidator>
#include <QMessageBox>
#include <regex>
#include "list.h"
#include "code.h"
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
    void Add();

    void Replace_Code();

    QString return_name();

    bool File_deff();

private slots:





    void ReadFile();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    int rSize =0;
    int MaxSize = 32000;
    List_class* SOREV;
    QStandardItemModel* table;
    QString str;
    int check_count=0;
    bool vosh = false;
    QString filePath;
    QString text;

};
#endif // MAINWINDOW_H
