#include <iostream>

template<typename T>
class VectorReverseIterator : std::iterator<std::input_iterator_tag, T> {
private:
    
    typedef T* pointer;

public:
    explicit VectorReverseIterator(pointer p) : m_ptr(p) {};
    VectorReverseIterator(const VectorReverseIterator& it) : m_ptr(it.m_ptr) {};

    
    friend bool operator !=(VectorReverseIterator const& a, VectorReverseIterator const& b)
    {
        return a.m_ptr != b.m_ptr;
    };
    friend bool operator ==(VectorReverseIterator const& a, VectorReverseIterator const& b)
    {
        return a.m_ptr == b.m_ptr;
    };

   
    T& operator*() { return *m_ptr; };
    T* operator->() { return m_ptr; }

  
    VectorReverseIterator operator--(int) { VectorReverseIterator<T> temp = *this; ++(*this); return temp; }
    VectorReverseIterator operator++(int) { VectorReverseIterator<T> temp = *this; --(*this); return temp; }
    VectorReverseIterator& operator++() { m_ptr--; return *this; }
    VectorReverseIterator& operator--() { m_ptr++; return *this; }
    VectorReverseIterator operator+(int number) { VectorReverseIterator<T> temp = *this; temp.m_ptr -= number; return temp; }
    VectorReverseIterator operator-(int number) { VectorReverseIterator<T> temp = *this; temp.m_ptr += number; return temp; }
    VectorReverseIterator& operator+=(int number) { m_ptr -= number; return *this; }
    VectorReverseIterator& operator-=(int number) { m_ptr += number; return *this; }

    
    friend int operator-(const VectorReverseIterator& first, const VectorReverseIterator& second) {
        return first.m_ptr - second.m_ptr;
    }
   
    explicit operator VectorReverseIterator<const T>() { return VectorReverseIterator<const T>(m_ptr); }

private:
    pointer m_ptr;
};




