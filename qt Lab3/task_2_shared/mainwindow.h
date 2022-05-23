#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
template<class T>
class shared_ptr
{
public:
    shared_ptr() : ptr(nullptr), RefCount(new int(0)) {};

    shared_ptr(T* ptr) : ptr(ptr), RefCount(new int(1)) {};

    shared_ptr( const shared_ptr<T>& OtherShared_ptr) : ptr(OtherShared_ptr.ptr), RefCount(OtherShared_ptr.RefCount) {

        if (nullptr != OtherShared_ptr.ptr) {
            (*this->RefCount)++;
        }
    }
    shared_ptr( const shared_ptr<T>&& OtherShared_ptr) : ptr(std::move(OtherShared_ptr.ptr)), RefCount(std::move(OtherShared_ptr.RefCount)) {
        if (ptr == nullptr) return;

        OtherShared_ptr.ptr = nullptr;
        OtherShared_ptr.RefCount = nullptr;

        ++(*RefCount);
    }
    shared_ptr<T>& operator=(shared_ptr<T>& OtherShared_ptr) {
        if (this == &OtherShared_ptr) return *this;

        (*RefCount)--;
        if (*RefCount == 0) {
            delete ptr;
            delete RefCount;
        }

        ptr = OtherShared_ptr.ptr;
        RefCount = OtherShared_ptr.RefCount;

        if (nullptr != OtherShared_ptr.ptr) {
            (*this->RefCount)++;
        }

        return *this;
    };
    shared_ptr<T>& operator=(shared_ptr<T>&& OtherShared_ptr) {

        if (this == &OtherShared_ptr) return *this;


        (*RefCount)--;
        if (*RefCount == 0) {
            delete ptr;
            delete RefCount;
        }


        ptr = (OtherShared_ptr.ptr);
        RefCount = (OtherShared_ptr.RefCount);

        OtherShared_ptr.ptr = nullptr;
        OtherShared_ptr.RefCount = nullptr;

        return *this;
    };
    ~shared_ptr()
    {
        if (!RefCount) return;
        --* RefCount;
        if (!*RefCount) {
            delete ptr;
            delete RefCount;
        }
    }

    T* operator->()
    {
        return ptr;
    };
    T& operator*() const noexcept {
        return *ptr;
    };

    template <class U>
    void reset(U* newptr)
    {
        delete ptr;
        delete RefCount;

        ptr = newptr;
        RefCount = new int(0);
    };

    void swap(shared_ptr<T>& OtherShared_ptr) noexcept {
        std::swap(ptr, OtherShared_ptr.ptr);
        std::swap(RefCount, OtherShared_ptr.RefCount);
    };

    //returns a pointer or nullptr
    T* get() const noexcept
    {
        return ptr;
    };

    int use_count()
    {
        return *RefCount;
    }

private:
    T* ptr;
    int* RefCount;//счетчик ссылок
};

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
    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    shared_ptr<int>* arr = new shared_ptr<int>[10];
    Ui::MainWindow *ui;
    QStandardItemModel* table;
};
#endif // MAINWINDOW_H
