#pragma once

#include <iostream>

template <class T>
class Stack {
public:
    Stack();
    Stack(const int);
    Stack(const Stack<T> &);
    ~Stack();

    Stack & operator=(const Stack<T> &);

    template <class Y>
    friend std::ostream & operator<<(std::ostream &, const Stack<Y> &);

    void push(const T &);
    T pop();
    bool is_empty() const;
    T peek() const;
    void display() const;

private:
    T * m_arr;
    size_t m_size;
    size_t m_capacity;
};

template <class T>
Stack<T>::Stack() {
    m_arr = nullptr;
    m_size = 0;
    m_capacity = 0;
}
template <class T>
Stack<T>::Stack(const int capacity) {
    m_arr = new T[capacity];
    m_size = 0;
    m_capacity = capacity;
}
template <class T>
Stack<T>::Stack(const Stack<T> &obj) {
    m_arr = nullptr;
    m_size = obj.m_size;
    m_capacity = obj.m_capacity;

    if (m_capacity) {
        m_arr = new T[m_capacity];
    }
    
    for (size_t i = 0; i < m_size; i ++) {
        m_arr[i] = obj.m_arr[i];
    }
}
template <class T>
Stack<T>::~Stack() {
    delete[] m_arr;
    m_arr = nullptr;
    m_size = 0;
    m_capacity = 0;
}

template <class T>
Stack<T> & Stack<T>::operator=(const Stack<T> &obj) {
    if (this != &obj) {
        delete[] m_arr;

        m_arr = nullptr;
        m_size = obj.m_size;
        m_capacity = obj.m_capacity;

        if (m_capacity) {
            m_arr = new T[m_capacity];
        }
        
        for (size_t i = 0; i < m_size; i ++) {
            m_arr[i] = obj.m_arr[i];
        }
    }
    return *this;
}

template <class T>
std::ostream & operator<<(std::ostream &out, const Stack<T> &obj) {
    for (size_t i = 0; i < obj.m_size; i ++) {
        out << obj.m_arr[i] << std::endl;
    }
    return out;
}

template <class T>
void Stack<T>::push(const T &obj) {
    if (m_size == m_capacity) {
        T * temp = new T[++ m_capacity];
        for (size_t i = 0; i < m_size; i ++) {
            temp[i] = m_arr[i];
        }
        temp[m_size] = obj;

        delete[] m_arr;
        m_arr = temp;
    }
    else {
        m_arr[m_size] = obj;
    }
    m_size ++;
}

template <class T>
T Stack<T>::pop() {
    if (!m_size) {
        throw "Stack is empty";
    }
    T temp = peek();
    m_size --;
    return temp;
}

template <class T>
bool Stack<T>::is_empty() const {
    return !m_size;
}

template <class T>
T Stack<T>::peek() const {
    if (!m_size) {
        throw "Stack is empty";
    }
    return m_arr[m_size - 1];
}

template <class T>
void Stack<T>::display() const {
    std::cout << *this;
}
