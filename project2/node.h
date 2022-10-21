#pragma once

template<class T>
struct Node {
    Node();
    Node(const T &);
    ~Node();

    T * data;
    Node<T> * next;
};

template<class T>
Node<T>::Node() {
    data = nullptr;
    next = nullptr;
}
template<class T>
Node<T>::Node(const T &obj) {
    data = new T(obj);
    next = nullptr;
}
template<class T>
Node<T>::~Node() {
    delete data;
    data = nullptr;
    next = nullptr;
}
