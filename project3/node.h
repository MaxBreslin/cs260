// node.h - Node template struct declaration and implementation

#pragma once

#include <iostream>

template<class K, class V>
struct Node {
    Node();
    Node(const K &, const V &);
    ~Node();

    Node & operator=(const Node<K, V> &);

    template<class kK, class vV>
    friend std::ostream & operator<<(std::ostream &, const Node<kK, vV> &);

    K * key;
    V * value;
    Node<K, V> * next;
};

template<class K, class V>
Node<K, V>::Node() {
    key = nullptr;
    value = nullptr;
    next = nullptr;
}
template<class K, class V>
Node<K, V>::Node(const K &key, const V &value) {
    this->key = new K(key);
    this->value = new V(value);
    next = nullptr;
}
template<class K, class V>
Node<K, V>::~Node() {
    delete key;
    delete value;
    key = nullptr;
    value = nullptr;
    next = nullptr;
}

template<class K, class V>
Node<K, V> & Node<K, V>::operator=(const Node<K, V> &obj) {
    if (this != &obj) {
        delete key;
        delete value;
        key = new K(*obj.key);
        value = new V(*obj.value);
        next = obj.next;
    }
    return *this;
}

template<class K, class V>
std::ostream & operator<<(std::ostream &out, const Node<K, V> &obj) {
    out << obj.value;
    return out;
}
