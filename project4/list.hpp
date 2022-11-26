#pragma once

// list.h - List template class declaration and implementation (linear linked list)

#include <iostream>

template<class T>
class List {
public:
    List();
    List(const size_t);
    List(const List &);
    ~List();

    List & operator=(const List &);

    template<class tT>
    friend std::ostream & operator<<(std::ostream &, const List<tT> &);

    // Returns the element at the passed index
    T operator[](size_t) const;

    // Inserts the passed element at the front of the list
    void insert(const T &);

    // Removes all elements in the list with the passed value and returns a list
    // of the values that were removed
    List<T> remove(const T &);

    // Displays the list
    void display() const;

    // Returns the number of elements in the list
    size_t length() const;

private:
    T * m_array;
    size_t m_size;
    size_t m_capacity;
    
    static const size_t DEFAULT_SIZE = 10;
};

template<class T>
List<T>::List() {
    m_array = new T[DEFAULT_SIZE];
    m_size = 0;
    m_capacity = DEFAULT_SIZE;
}
template<class T>
List<T>::List(const size_t capacity) {
    m_array = new T[capacity];
    m_size = 0;
    m_capacity = capacity;
}
template<class T>
List<T>::List(const List &obj) {
    m_array = new T[obj.m_capacity];
    m_size = obj.m_size;
    m_capacity = obj.m_capacity;

    for (size_t i = 0; i < m_size; i ++) {
        m_array[i] = obj.m_array[i];
    }
}
template<class T>
List<T>::~List() {
    delete[] m_array;
    m_array = nullptr;
    m_size = 0;
    m_capacity = 0;
}

template<class T>
List<T> & List<T>::operator=(const List &obj) {
    if (this != &obj) {
        delete[] m_array;

        m_array = new T[obj.m_capacity];
        m_size = obj.m_size;
        m_capacity = obj.m_capacity;

        for (size_t i = 0; i < m_size; i ++) {
            m_array[i] = obj.m_array[i];
        }
    }
    return *this;
}

template<class T>
std::ostream & operator<<(std::ostream &out, const List<T> &obj) {
    for (size_t i = 0; i < obj.m_size; i ++) {
        out << i + 1 << ": " << obj.m_array[i] << std::endl;
    }
    
    return out;
}

template<class T>
T List<T>::operator[](size_t index) const {
    if (index >= m_size) {
        throw "Index out of range";
    }

    return m_array[index];
}

template<class T>
void List<T>::insert(const T &data) {
    if (m_size == m_capacity) {
        m_capacity *= 2;

        T * temp = new T[m_capacity];
        for (size_t i = 0; i < m_size; i ++) {
            temp[i] = m_array[i];
        }
        temp[m_size] = data;
        
        delete[] m_array;
        m_array = temp;
    }
    else {
        m_array[m_size] = data;
    }
    m_size ++;
}

template<class T>
List<T> List<T>::remove(const T &data) {
    List<T> removed(m_size);

    for (size_t i = 0; i < m_size; i ++) {
        if (data == m_array[i]) {
            removed.insert(m_array[i]);
            m_size --;
            for (size_t j = i; j < m_size; j ++) {
                m_array[j] = m_array[j + 1];
            }
            i --;
        }
    }

    return removed;
}

template<class T>
void List<T>::display() const {
    std::cout << *this << std::endl;
}

template<class T>
size_t List<T>::length() const {
    return m_size;
}
