#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
template<class T>
class shared_ptr
{
public:
    shared_ptr() : ptr(nullptr), RefCount(new int(0)) {};

    shared_ptr(T* ptr) : ptr(ptr), RefCount(new int(1)) {};
    shared_ptr(T* ptr, int*x):ptr(ptr),RefCount(x){
        (*RefCount)++;
    }

    shared_ptr( const shared_ptr<T>& OtherShared_ptr) : ptr(OtherShared_ptr.ptr), RefCount(OtherShared_ptr.RefCount) {//cs copy

        if (nullptr != OtherShared_ptr.ptr) {
            (*this->RefCount)++;
        }
    }
    shared_ptr( const shared_ptr<T>&& OtherShared_ptr) : ptr(std::move(OtherShared_ptr.ptr)), RefCount(std::move(OtherShared_ptr.RefCount)) {//cs move
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


    T* get() const noexcept
    {
        return ptr;
    };

    int* ref_count()
       {
           return RefCount;
       }

    int use_count()
    {
        return *RefCount;
    }

private:
    T* ptr;
    int* RefCount;//ReferenceCount
};

template<class T>
class weak
{
public:
    weak() : ptr(nullptr), RefCount(nullptr), Counter(new int(0)) {};

    weak(shared_ptr<T>& OtherShared_ptr) : ptr(OtherShared_ptr.operator->()), RefCount(OtherShared_ptr.ref_count()), Counter(new int(1)){//cs copy

        if (nullptr != OtherShared_ptr.operator->()) {
            (*this->Counter)++;
        }
    }

    weak<T>& operator =(weak<T>& other) {
        if ((this == &other) || (Counter == other.use_count()))
            return *this;
        (*Counter)--;
        ptr = other.ptr;
        RefCount = other.RefCount;
        Counter = other.Counter;
        (*Counter)++;
        return *this;

    }
    weak<T>& operator =(shared_ptr<T>& other) {
        if (ptr == other.get())
            return *this;
        ptr = other.get();
        RefCount = other.ref_count();
        if (*Counter != 1) {
            (*Counter)--;
            Counter = new int(1);
        }

        return *this;

    }

    shared_ptr<T> Lock(){



        if(*RefCount > 0){
            return shared_ptr<T>(ptr,RefCount);
        }else{
            return shared_ptr<T>();
        }

    }

    T* operator->()
    {
        return ptr;
    };
    T& operator*() const noexcept {
        return *ptr;
    };

    T* getweak() const noexcept
    {
        return ptr;
    };

    int* use_count()
    {
        return Counter;
    }

    int count()
    {
        return *Counter;
    }

    int* use_refcount()
    {
        return RefCount;
    }

    int refcount()
    {
        return* RefCount;
    }



    ~weak()
    {
        if (!RefCount) return;
        --* RefCount;
        if (!*RefCount) {
            delete ptr;
            delete RefCount;
            delete Counter;
        }
    }

private:
    T* ptr;
    int* RefCount;//ReferenceCount
    int* Counter;
};
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_weak_to_weak_clicked();

    void on_shared_to_weak_clicked();

    void on_weak_to_shared_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    shared_ptr<int>* arr = new shared_ptr<int>[10];
    weak<int>* woo = new weak<int>[10];

    QStandardItemModel* table;
    QStandardItemModel* table1;

};
#endif // MAINWINDOW_H
