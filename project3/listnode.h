// listnode.h - Node template struct declaration and implementation

#pragma once

#include <iostream>

template<class T>
struct ListNode {
    ListNode();
    ListNode(const T &);
    ~ListNode();

    ListNode & operator=(const ListNode<T> &);

    T * data;
    ListNode<T> * next;
};

template<class T>
ListNode<T>::ListNode() {
    data = nullptr;
    next = nullptr;
}
template<class T>
ListNode<T>::ListNode(const T &obj) {
    data = new T(obj);
    next = nullptr;
}
template<class T>
ListNode<T>::~ListNode() {
    delete data;
    data = nullptr;
    next = nullptr;
}

template<class T>
ListNode<T> & ListNode<T>::operator=(const ListNode<T> &obj) {
    if (this != &obj) {
        delete data;
        data = new T(*obj.data);
        next = obj.next;
    }
    return *this;
}
