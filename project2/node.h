#pragma once

#include "person.h"

template<class T>
struct Node {
    Node();
    Node(const T &);
    ~Node();

    T * data;
    Node<T> * next;
};
