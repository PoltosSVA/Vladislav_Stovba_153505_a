#include <iostream>




template <typename T>
class VectorIterator : std::iterator<std::input_iterator_tag, T> {
private:

    typedef T* pointer;

public:
    explicit VectorIterator(pointer p) : m_ptr(p) {};
    VectorIterator(const VectorIterator& it) : m_ptr(it.m_ptr) {};

    
    friend bool operator !=(VectorIterator const &a, VectorIterator const &b)
    {return a.m_ptr != b.m_ptr;};
    friend bool operator ==(VectorIterator const &a, VectorIterator const &b)
    {return a.m_ptr == b.m_ptr;};

    
    T& operator*() {return *m_ptr; };
    T* operator->() {return m_ptr; }

   
    VectorIterator operator++(int) { VectorIterator<T> temp = *this; ++(*this); return temp;}
    VectorIterator operator--(int) { VectorIterator<T> temp = *this; --(*this); return temp;}
    VectorIterator& operator++() { m_ptr++; return *this;}
    VectorIterator& operator--() { m_ptr--; return *this;}
    VectorIterator operator+(int number) {VectorIterator<T> temp = *this; temp.m_ptr += number; return temp;}
    VectorIterator operator-(int number) {VectorIterator<T> temp = *this; temp.m_ptr -= number; return temp;}
    VectorIterator& operator+=(int number) {m_ptr += number; return *this;}
    VectorIterator& operator-=(int number) {m_ptr -= number; return *this;}


    
    friend int operator-(const VectorIterator& first, const VectorIterator& second) {
        return first.m_ptr - second.m_ptr;
    }
  
    operator VectorIterator<const T>() {return VectorIterator<const T>(m_ptr);}

private:
pointer m_ptr;
};





