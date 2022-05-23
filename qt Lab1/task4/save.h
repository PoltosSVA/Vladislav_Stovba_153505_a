#ifndef SAVE_H
#define SAVE_H

#include <QMainWindow>
#include "book.h"
#include <QRegularExpressionValidator>
namespace Ui {
class Save;
}

class Save : public QMainWindow
{
    Q_OBJECT

public:
    explicit Save(QWidget *parent = nullptr, Book *booklist =nullptr, int *countbooklist = nullptr);
    ~Save();

public:
    QString return_name();
    QString return_ser_name();
    QString return_second_name();
    QString return_publishing();
    QString return_book_title();
    QString return_pages();
    QString return_y_publish();
signals:
     void Savetable();
     void sign();
public slots:
     void saveslot();
private slots:
     void on_pushButton_clicked();

private:
    Ui::Save *ui;
    Book *book_list;
    int *count_book_list;
    QRegularExpressionValidator name_;
    QRegularExpressionValidator sername_;
    QRegularExpressionValidator secondname_;
    QRegularExpressionValidator publishing_;
    QRegularExpressionValidator booktitle_;
};

#endif // SAVE_H
