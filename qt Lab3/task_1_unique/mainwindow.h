#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE




template <typename T>
class unique_ptr{
private:
    T* ptr;
public:

    unique_ptr(unique_ptr const& other) = delete;// удаляем конст копирования
    unique_ptr& operator=(unique_ptr const& other) = delete;//удал присваивание

    unique_ptr()
        : ptr(nullptr) {}
    unique_ptr(T* ptr) {
        this->ptr = ptr;
    }
    ~unique_ptr() {
        delete ptr;
    }

    T& operator*() const {
        return *ptr;
    }

    T* operator->() const noexcept {
        return ptr;
    }

    T* get() const noexcept{//получаем указатель внутри юника
        return ptr;
    }

    void set(T* ptr) {
            this->ptr = ptr;
    }

    T* release() noexcept{// зануляем ptr и возвращаем старое значение
        T* temp = ptr;
        ptr = nullptr;
        return temp;
    }

    void reset(T p) noexcept{//заменяем старый указатель на новый + делит
        delete ptr;
        T* z = new int(p);
        ptr = z;
    }


    void move(unique_ptr& mp) {//ivalue в rvalue беру из одного и прекидыаю в другой
        ptr = mp.ptr;
        mp.ptr = nullptr;
    }

    void swap (unique_ptr& x) noexcept{//Обменивает содержимое объекта unique_ptr на содержимое объекта x , передавая право собственности на любой управляемый объект между ними, не уничтожая ни того, ни другого.



        T* tmp = ptr;
        ptr = x.ptr;
        x.ptr = tmp;
    }

};




class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void refresh_table();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    QStandardItemModel* table;

    unique_ptr<int>* arr = new unique_ptr<int>[10];

    int* a[10];
    int num =0;
    QString str;
    int ch_box = 0;
    int ch_box_1 = 0;
};
#endif // MAINWINDOW_H
