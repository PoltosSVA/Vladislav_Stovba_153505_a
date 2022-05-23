#ifndef LIST_H
#define LIST_H

#include <QMainWindow>
#include <QFile>
#include "book.h"
#include "QStandardItemModel"
#include <QRegularExpressionValidator>
namespace Ui {
class List;
}

class List : public QMainWindow
{
    Q_OBJECT

public:
    List(QWidget *parent = nullptr, Book *booklist =nullptr, int *countbooklist = nullptr);

    ~List();

public:
    QString return_name();
    QString return_ser_name();
    QString return_second_name();
    QString return_publishing();
    QString return_book_title();
    QString return_pages();
    QString return_y_publish();
private:

    //void LoadFromFile(QFile &File);
signals:
    void refreshTable();
    void sig();
  //  void save_in_file();
private:
    Ui::List *ui;
    Book* fCheck(Book *book, int rSize, int MasSize);
    QRegularExpressionValidator name_;
    QRegularExpressionValidator sername_;
    QRegularExpressionValidator secondname_;
    QRegularExpressionValidator publishing_;
    QRegularExpressionValidator booktitle_;
public slots:
    void slot();
private slots:
    void on_pushButton_clicked();
private:
    Book *book_list;
    int *count_book_list;
    int *edit_num;
};

#endif // LIST_H
