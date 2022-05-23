#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "list.h"
#include "book.h"
#include <QFile>
#include <QStandardItemModel>
#include <QString>
#include <QFileDialog>
#include <QMessageBox>
#include "save.h"
#include <regex>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public:

    int check_count =0;
    Book* fCheck(Book *book, int, int);
    void Range();
    void File_Add();
    void From_table_to_Massiv();
    void Search_publishing();
    void FileDelete();
    void CheckVoid();
    bool File_deff();
    void show_Error();

private:
    void LoadTextFile();

private:

    Ui::MainWindow *ui;

    QRegularExpressionValidator name__;
    QRegularExpressionValidator sername__;
    QRegularExpressionValidator secondname__;
    QRegularExpressionValidator publishing__;
    QRegularExpressionValidator booktitle__;


    Book *book;
    QString str;
    QString strv;
    //QString str;
    Book *book_list;
    int rSize =0;
    int MaxSize=1000;
    QStandardItemModel *table;
    bool vosh=false;
    int NumEdit;
    int NumDel ;


signals:
    void signal();




private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_5_clicked();
    void refresh_table();
    void metodStandart();
    void metodCheck();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_9_clicked();

};


#endif // MAINWINDOW_H
