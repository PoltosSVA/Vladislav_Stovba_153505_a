#include <iostream>
#include <memory>
#include <string>
#include <xmemory>
#include "VectorIterator.h"
#include "VectorReverseIterator.h"


template<typename T>

struct RawMemory {//типо аллокатор(может хранить данные для контейнера с которым работает)
    T* buf = nullptr;//указатель на начало памяти
    size_t cap = 0;//макс размер

    static T* Allocate(size_t _n) {//выделяет достаточное кол-во памяти для содержания _n объектов типа T
        return static_cast<T*>(operator new(_n * sizeof(T)));//способ выделения памяти
    }//возвращает указатель на начальный элемент памяти

    static void Deallocate(T* buf) {
        operator delete(buf);//освобождает выделенную память(элементы массива не уничтожаются при вызове этой функции)
    }

    RawMemory() = default;//ключевое слово default указывает компилятору самостоятельно формировать
      // соответствующий конструктор, если такой не объявлен в классе

    RawMemory(const RawMemory&) = delete;
    RawMemory& operator = (const RawMemory&) = delete;

    RawMemory(RawMemory&& other)  noexcept {
        Swap(other);
    }

    RawMemory& operator = (RawMemory&& other)  noexcept {
        Swap(other);
        return *this;
    }

    void Swap(RawMemory& other) {
        std::swap(cap, other.cap);
        std::swap(buf, other.buf);
    }


    RawMemory(size_t _n) : cap(_n) {
        buf = Allocate(_n);
    }

    ~RawMemory() {
        Deallocate(buf);
    }

    T* operator +(size_t i) {
        return buf + i;
    }
    const T* operator +(size_t i) const {
        return buf + i;
    }
    T& operator[](size_t i) {
        return buf[i];
    }
    const T& operator[](size_t i) const {
        return buf[i];
    }
};

template<typename T>
class Vector {


private:
    RawMemory<T> data;//хранилище
    size_t m_size = 0;//текущая заполненность

    static void Construct(void* buf) {
        new (buf) T();//адрес тип выбираем блок памяти создаем объект T в адресе буф 
    }
    static void Construct(void* buf, const T& element) {
        new (buf) T(element);
    }
    static void Construct(void* buf, T&& element) {
        new (buf) T(std::move(element));//перемещаем содрежимое
    }
    static void Destruct(T* buf) {
        buf->~T();
    }

public:

    typedef T value_type;
    typedef const value_type& const_reference  ;
    typedef value_type& reference;
    typedef size_t size_type;
    typedef VectorIterator<T> iterator;
    typedef VectorIterator <const T>const_iterator;
    typedef VectorReverseIterator<T> reverse_iterator;
    typedef VectorReverseIterator <const T> const_reverse_iterator;

    explicit Vector() = default;

    explicit Vector(size_type _n) : data(_n) {
        std::uninitialized_value_construct_n(data.buf, _n);//Создает указанное количество объектов итератора value_type по инициализации значения, начиная с указанного местоположения.
        m_size = _n;
    }

    Vector(const Vector& other) : data(other.m_size) {
        std::uninitialized_copy_n(other.data.buf, other.m_size, data.buf);//копирует кол-во элементов из одного в другое
        m_size = other.m_size;
    }

    Vector(std::initializer_list<T> _l) : data(_l.size()) {
        std::uninitialized_copy_n(_l.begin(), _l.size(), data.buf);
        m_size = _l.size();

    }

    Vector(Vector&& other)  noexcept {
        Swap(other);
    }
    ~Vector() {
        std::destroy_n(data.buf, m_size);//уничтощает кол-во элементов(от куда до куда)
    }
    void Swap(Vector& other) {
        data.Swap(other.data);
        std::swap(m_size, other.m_size);
    }

    Vector& operator = (Vector&& other)  noexcept {
        Swap(other);
        return *this;
    }

    Vector& operator = (const Vector& other) {
        if (data.cap < other.m_size) {
            Vector temp(other);
            Swap(temp);
        }
        else {
            for (size_t i = 0; i < m_size && i < other.m_size; ++i) {
                data[i] = other.data[i];
            }
            if (m_size > other.m_size) {
                std::destroy_n(data.buf + other.m_size,//12 10 доход до 10 и 12 - 10 =2 убираем 2
                    m_size - other.m_size);
            }
            else if (m_size < other.m_size) {
                std::uninitialized_copy_n(other.data.buf + m_size,
                    other.m_size - m_size,
                    data.buf + m_size);
            }
            m_size = other.m_size;
        }
        return *this;
    }
    void resize(size_type _n) {

        reserve(_n);
        if (m_size < _n) {
            std::uninitialized_value_construct_n(data.buf + m_size, _n - m_size);
        }
        else if (m_size > _n) {
            std::destroy_n(data.buf, m_size - _n);
        }
        m_size = _n;
    }

    void resize(size_type _n, const value_type& _x) {//увелич размер контейнера
        reserve(_n);
        if (m_size < _n) {
            std::uninitialized_fill_n(data.buf, _n - m_size, _x);//копирует n элементов их _x в буф
        }
        else {
            std::destroy_n(data.buf + m_size, m_size - _n);
        }
        m_size = _n;
    }

    void reserve(size_type _n) {//Требует, чтобы емкость вектора была достаточной, по крайней мере, для содержания n элементов.
        if (_n > data.cap) {
            RawMemory<T> data2(_n);//контейнер увеличивает свое хранилище
            std::uninitialized_move_n(data.buf, m_size, data2.buf);
            std::destroy_n(data.buf, m_size);
            data.Swap(data2);
        }
    }
    //предоставляющий доступ к массиву объектов типа const T.
    void assign(std::initializer_list<value_type> _l) {//дает вектору новое содержимое изменяя его размер
        auto it = this->begin();
        for (auto i : _l) {
            *it = i;
            it++;
        }
        m_size = _l.size();
    }

    void assign(size_type _n, const value_type& _x) {
        auto it = this->begin();
        for (int i = 0; i < _n; ++i) {
            *it = _x;
            it++;
        }
        m_size = _n;
    }

    void push_back(const value_type& _x) {
        if (m_size == data.cap) {
            if (m_size == 0) {
                reserve(1);
            }
            else {
                reserve(m_size * 2);
            }
            
        }
        new (data.buf + m_size) T(_x);//даем объекту Т место в буфе с определенного элемента
        m_size++;
    }

    void push_back(value_type&& _x) {
        if (m_size == data.cap) {
            if (m_size == 0) {
                reserve(1);
            }
            else {
                reserve(m_size * 2);
            }
        }
        new (data.buf + m_size) T(std::move(_x));
        m_size++;
    }

    void pop_back() noexcept {
        std::destroy_at(data.buf + m_size - 1);//определенный объект который нужно убрать
        m_size--;
    }

    template<typename... Args>
    constexpr reference emplace_back(Args&&... _args) {
        if (m_size == data.cap) {
            if (m_size == 0) {
                reserve(1);
            }
            else {
                reserve(m_size * 2);
            }
        }
        //Функция std::move не выполняет никаких перемещений. Как уже было сказано выше, она выполняет приведение типа к rvalue-ссылке.
        //Идеальная передача позволяет создавать функции-обертки, передающие параметры без каких-либо изменений (lvalue передаются как lvalue, а rvalue – как rvalue) 
        auto ptr = new(data.buf + m_size) T(std::forward<Args>(_args)...);
        m_size++;
        return *ptr;
    }

    template<typename... Args>
    constexpr iterator emplace(const_iterator _position, Args&&... _args) {
        if (m_size == data.cap) {
            if (m_size == 0) {
                reserve(1);
            }
            else {
                reserve(m_size * 2);
            }
        }
        size_t num = m_size;
        auto current_it = this->begin();
        
        for (auto it = this->cbegin(); it != _position; it++, current_it++);
        
        for (auto it = this->end(); it != current_it; --it, --num) {
            *(it) = *(it - 1);
        }

        new(data.buf + num) T(std::forward<Args>(_args)...);
        m_size++;
        return current_it;
    }

    iterator insert(const_iterator _position, const value_type& _x) {
        if (m_size == data.cap) {
            if (m_size == 0) {
                reserve(1);
            }
            else {
                reserve(m_size * 2);
            }
        }
        size_t num = m_size;
        auto current_it = this->begin();
        for (auto it = this->cbegin(); it != _position; it++, current_it++) {}
        for (auto it = this->end(); it != current_it; --it, --num) {
            *(it) = *(it - 1);
        }

        new(data.buf + num) T(_x);
        m_size++;
        return current_it;
    }

    iterator insert(const_iterator _position, value_type&& _x) {
        if (m_size == data.cap) {
            if (m_size == 0) {
                reserve(1);
            }
            else {
                reserve(m_size * 2);
            }
        }
        size_t num = m_size;

        auto current_it = this->begin();
        for (auto it = this->cbegin(); it != _position; it++, current_it++) {}
        for (auto it = this->end(); it != current_it; --it, --num) {
            *it = *(it - 1);
        }
        new (data.buf + num) T(std::move(_x));
        m_size++;
        return current_it;
    }
    iterator insert(const_iterator _position, std::initializer_list<value_type> _l) {
        if (m_size + _l.size() > data.cap) {
            if (data.cap == 0) {
                reserve(1);
            }
            else {
                reserve(data.cap * 2);
            }
            
        }
        size_t num = m_size;
        auto current_it = this->begin();
        for (auto it = this->cbegin(); it != _position; it++, current_it++) {}
        for (auto it = this->end(); it != current_it; --it, --num) {
            *(it + _l.size() - 1) = *(it - 1);
        }
        for (int i : _l) {
            new (data.buf + num) T(i);
            num++;
        }
        m_size += _l.size();
        return current_it;
    }

    iterator insert(const_iterator _position, size_type _n, const value_type& _x) {
        if (m_size + _n > data.cap) {
            if (data.cap == 0) {
                reserve(1);
            }
            else {
                reserve(data.cap * 2);
            }

        }
        size_t num = m_size;
        auto current_it = this->begin();

        for (auto it = this->cbegin(); it != _position; it++, current_it++);
        for (auto it = this->end(); it != current_it; --it, --num) {
            *(it + _n - 1) = *(it - 1);
        }
        for (int i = 0; i < _n; ++i) {
            new (data.buf + num) T(_x);
            num++;
        }
        m_size += _n;
        return current_it;
    }


    iterator erase(const_iterator _position) {//удаляет 1 элем
        auto current_it = this->begin();
        for (auto cit = this->cbegin(); cit != _position; ++cit, ++current_it);//доходим до выбранного элем
        for (auto it = current_it; it != this->end() - 1; ++it) {//тот который хочем удалить присваиваем некст
            *(it) = *(it + 1);
        }
        m_size--;
        return current_it;
    }

    iterator erase(const_iterator _first, const_iterator _last) {//удаляет  элем от ф до с
        size_type _n = _last - _first;
        auto current_it_first = this->begin();
        auto current_it_last = this->begin();
        for (auto cit = this->cbegin(); cit != _first; ++cit, ++current_it_first) {}
        for (auto cit = this->cbegin(); cit != _last; ++cit, ++current_it_last) {}
        
        for (auto it = current_it_first; it != this->end(); ++it) {
            *(it) = *(it + _n);
        }
        m_size -= _n;
        return current_it_first;
    }

    reference front() noexcept {//1-й элем вектора
        return data[0];
    }
    reference back() noexcept {//последний элем вектора
        return data[m_size - 1];
    }
    reference at(size_type _n) noexcept {//потипу [] ссылка на элем
        if (_n < 0 || _n >= m_size) {
            throw new std::out_of_range("out");
        }
        return data[_n];
    }

    void clear() {
        m_size = 0;
    }

    bool empty() const noexcept {
        return m_size == 0;
    }
    size_t size() const noexcept {
        return m_size;
    }

    size_t max_size() const noexcept {//контейнер может содержать из-за ограничений реализации системы или библиотек
        size_t ret = -1;
        return ret;
    }
    

    reference operator [](int index) {
        return data[index];
    }

    const_reference operator [](int index) const {
        return data[index];
    }


    iterator begin() noexcept {//Возвращает итератор, указывающий на первый элемент вектора .
        return iterator(data.buf);
    }
    iterator end() noexcept {//Возвращает итератор, указывающий на последний элемент вектора .
        return iterator(data.buf + m_size);
    }


    const_iterator cbegin() noexcept {//тоже самое но для констант
        return const_iterator(data.buf);
    }
    const_iterator cend() noexcept {
        return const_iterator(data.buf + m_size);
    }


    reverse_iterator rbegin() noexcept {//указывает на конец его увеличение ведет к началу
        return reverse_iterator(data.buf + m_size - 1);
    }
    reverse_iterator rend() noexcept {//указ на начало увеличение к концу
        return reverse_iterator(data.buf - 1);
    }


    const_reverse_iterator crbegin() noexcept {//тоже самое  но на константу
        return const_reverse_iterator(data.buf + m_size - 1);
    }
    const_reverse_iterator crend() noexcept {
        return const_reverse_iterator(data.buf - 1);
    }
};
//Пары
template<typename A, typename B>
class Pair {
public:

    A first;
    B second;

    Pair() = default;

    Pair(A a, B b) : first(a), second(b) {}

    Pair(const Pair<A, B>& _pair) noexcept : first(_pair.first), second(_pair.second) {}

    void swap(Pair<A, B>& tem) {
        A tempT = tem.first;
        B tempU = tem.second;
        tem.first = first;
        tem.second = second;
        first = tempT;
        second = tempU;
    }
    friend constexpr Pair<A, B> make_pair(A&& a, B&& b);
   

};
template<typename A, typename B>
Pair<A, B> constexpr make_pair(A&& a, B&& b) {
    Pair<A, B> temp{ std::forward<A>(a), std::forward<B>(b) };
    return temp;
}


