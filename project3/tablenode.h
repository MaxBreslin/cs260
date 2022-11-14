// tablenode.h - Node template struct declaration and implementation

#pragma once

#include <iostream>

template<class K, class V>
struct TableNode {
    TableNode();
    TableNode(const K &, const V &);
    ~TableNode();

    TableNode & operator=(const TableNode<K, V> &);

    template<class kK, class vV>
    friend std::ostream & operator<<(std::ostream &, const TableNode<kK, vV> &);

    K * key;
    V * value;
    TableNode<K, V> * next;
};

template<class K, class V>
TableNode<K, V>::TableNode() {
    key = nullptr;
    value = nullptr;
    next = nullptr;
}
template<class K, class V>
TableNode<K, V>::TableNode(const K &key, const V &value) {
    this->key = new K(key);
    this->value = new V(value);
    next = nullptr;
}
template<class K, class V>
TableNode<K, V>::~TableNode() {
    delete key;
    delete value;
    key = nullptr;
    value = nullptr;
    next = nullptr;
}

template<class K, class V>
TableNode<K, V> & TableNode<K, V>::operator=(const TableNode<K, V> &obj) {
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
std::ostream & operator<<(std::ostream &out, const TableNode<K, V> &obj) {
    out << obj.value;
    return out;
}
