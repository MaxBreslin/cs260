#pragma once

#include "list.hpp"
#include <iostream>
#include <cmath>

template<class K, class V>
struct AVLTreeNode {
    AVLTreeNode();
    AVLTreeNode(const K &, const V &);
    ~AVLTreeNode();

    AVLTreeNode & operator=(const AVLTreeNode<K, V> &);

    template<class kK, class vV>
    friend std::ostream & operator<<(std::ostream &, const AVLTreeNode<kK, vV> &);

    K * key;
    V * value;
    unsigned int height;

    AVLTreeNode<K, V> * left;
    AVLTreeNode<K, V> * right;
};

template<class K, class V>
AVLTreeNode<K, V>::AVLTreeNode() {
    key = nullptr;
    value = nullptr;
    height = 0;

    left = nullptr;
    right = nullptr;
}

template<class K, class V>
AVLTreeNode<K, V>::AVLTreeNode(const K &key, const V &value) {
    this->key = new K(key);
    this->value = new V(value);
    height = 0;

    left = nullptr;
    right = nullptr;
}

template<class K, class V>
AVLTreeNode<K, V>::~AVLTreeNode() {
    delete key;
    delete value;
    key = nullptr;
    value = nullptr;
    height = 0;

    left = nullptr;
    right = nullptr;
}

template<class K, class V>
AVLTreeNode<K, V> & AVLTreeNode<K, V>::operator=(const AVLTreeNode<K, V> &obj) {
    if (this != &obj) {
        delete key;
        delete value;
        key = new K(*obj.key);
        value = new V(*obj.value);
        height = obj.height;

        left = obj.left;
        right = obj.right;
    }
    return this;
}

template<class K, class V>
std::ostream & operator<<(std::ostream &out, const AVLTreeNode<K, V> &obj) {
    out << *obj.value;
    return out;
}

