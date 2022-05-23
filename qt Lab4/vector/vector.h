#include <iostream>
#include <memory>
#include <string>
#include <xmemory>
#include "VectorIterator.h"
#include "VectorReverseIterator.h"


template<typename T>

struct RawMemory {//���� ���������(����� ������� ������ ��� ���������� � ������� ��������)
    T* buf = nullptr;//��������� �� ������ ������
    size_t cap = 0;//���� ������

    static T* Allocate(size_t _n) {//�������� ����������� ���-�� ������ ��� ���������� _n �������� ���� T
        return static_cast<T*>(operator new(_n * sizeof(T)));//������ ��������� ������
    }//���������� ��������� �� ��������� ������� ������

    static void Deallocate(T* buf) {
        operator delete(buf);//����������� ���������� ������(�������� ������� �� ������������ ��� ������ ���� �������)
    }

    RawMemory() = default;//�������� ����� default ��������� ����������� �������������� �����������
      // ��������������� �����������, ���� ����� �� �������� � ������

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
    RawMemory<T> data;//���������
    size_t m_size = 0;//������� �������������

    static void Construct(void* buf) {
        new (buf) T();//����� ��� �������� ���� ������ ������� ������ T � ������ ��� 
    }
    static void Construct(void* buf, const T& element) {
        new (buf) T(element);
    }
    static void Construct(void* buf, T&& element) {
        new (buf) T(std::move(element));//���������� ����������
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
        std::uninitialized_value_construct_n(data.buf, _n);//������� ��������� ���������� �������� ��������� value_type �� ������������� ��������, ������� � ���������� ��������������.
        m_size = _n;
    }

    Vector(const Vector& other) : data(other.m_size) {
        std::uninitialized_copy_n(other.data.buf, other.m_size, data.buf);//�������� ���-�� ��������� �� ������ � ������
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
        std::destroy_n(data.buf, m_size);//���������� ���-�� ���������(�� ���� �� ����)
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
                std::destroy_n(data.buf + other.m_size,//12 10 ����� �� 10 � 12 - 10 =2 ������� 2
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

    void resize(size_type _n, const value_type& _x) {//������ ������ ����������
        reserve(_n);
        if (m_size < _n) {
            std::uninitialized_fill_n(data.buf, _n - m_size, _x);//�������� n ��������� �� _x � ���
        }
        else {
            std::destroy_n(data.buf + m_size, m_size - _n);
        }
        m_size = _n;
    }

    void reserve(size_type _n) {//�������, ����� ������� ������� ���� �����������, �� ������� ����, ��� ���������� n ���������.
        if (_n > data.cap) {
            RawMemory<T> data2(_n);//��������� ����������� ���� ���������
            std::uninitialized_move_n(data.buf, m_size, data2.buf);
            std::destroy_n(data.buf, m_size);
            data.Swap(data2);
        }
    }
    //��������������� ������ � ������� �������� ���� const T.
    void assign(std::initializer_list<value_type> _l) {//���� ������� ����� ���������� ������� ��� ������
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
        new (data.buf + m_size) T(_x);//���� ������� � ����� � ���� � ������������� ��������
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
        std::destroy_at(data.buf + m_size - 1);//������������ ������ ������� ����� ������
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
        //������� std::move �� ��������� ������� �����������. ��� ��� ���� ������� ����, ��� ��������� ���������� ���� � rvalue-������.
        //��������� �������� ��������� ��������� �������-�������, ���������� ��������� ��� �����-���� ��������� (lvalue ���������� ��� lvalue, � rvalue � ��� rvalue) 
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


    iterator erase(const_iterator _position) {//������� 1 ����
        auto current_it = this->begin();
        for (auto cit = this->cbegin(); cit != _position; ++cit, ++current_it);//������� �� ���������� ����
        for (auto it = current_it; it != this->end() - 1; ++it) {//��� ������� ����� ������� ����������� �����
            *(it) = *(it + 1);
        }
        m_size--;
        return current_it;
    }

    iterator erase(const_iterator _first, const_iterator _last) {//�������  ���� �� � �� �
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

    reference front() noexcept {//1-� ���� �������
        return data[0];
    }
    reference back() noexcept {//��������� ���� �������
        return data[m_size - 1];
    }
    reference at(size_type _n) noexcept {//������ [] ������ �� ����
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

    size_t max_size() const noexcept {//��������� ����� ��������� ��-�� ����������� ���������� ������� ��� ���������
        size_t ret = -1;
        return ret;
    }
    

    reference operator [](int index) {
        return data[index];
    }

    const_reference operator [](int index) const {
        return data[index];
    }


    iterator begin() noexcept {//���������� ��������, ����������� �� ������ ������� ������� .
        return iterator(data.buf);
    }
    iterator end() noexcept {//���������� ��������, ����������� �� ��������� ������� ������� .
        return iterator(data.buf + m_size);
    }


    const_iterator cbegin() noexcept {//���� ����� �� ��� ��������
        return const_iterator(data.buf);
    }
    const_iterator cend() noexcept {
        return const_iterator(data.buf + m_size);
    }


    reverse_iterator rbegin() noexcept {//��������� �� ����� ��� ���������� ����� � ������
        return reverse_iterator(data.buf + m_size - 1);
    }
    reverse_iterator rend() noexcept {//���� �� ������ ���������� � �����
        return reverse_iterator(data.buf - 1);
    }


    const_reverse_iterator crbegin() noexcept {//���� �����  �� �� ���������
        return const_reverse_iterator(data.buf + m_size - 1);
    }
    const_reverse_iterator crend() noexcept {
        return const_reverse_iterator(data.buf - 1);
    }
};
//����
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


