#pragma once

// avltreenode.hpp - AVLTreeNode template class declaration and implementation

#include "list.hpp"
#include "string.hpp"
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

    K key;
    V value;
    size_t height;

    AVLTreeNode<K, V> * left;
    AVLTreeNode<K, V> * right;
};

template<class K, class V>
AVLTreeNode<K, V>::AVLTreeNode() {
    key = K();
    value = V();
    height = 1;

    left = nullptr;
    right = nullptr;
}

template<class K, class V>
AVLTreeNode<K, V>::AVLTreeNode(const K &key, const V &value) {
    this->key = key;
    this->value = value;
    height = 1;

    left = nullptr;
    right = nullptr;
}

template<class K, class V>
AVLTreeNode<K, V>::~AVLTreeNode() {
    key.~K();
    value.~V();
    height = 1;

    left = nullptr;
    right = nullptr;
}

template<class K, class V>
AVLTreeNode<K, V> & AVLTreeNode<K, V>::operator=(const AVLTreeNode<K, V> &obj) {
    if (this != &obj) {
        key = obj.key;
        value = obj.value;
        height = obj.height;

        left = obj.left;
        right = obj.right;
    }
    return this;
}

template<class K, class V>
std::ostream & operator<<(std::ostream &out, const AVLTreeNode<K, V> &obj) {
    out << obj.value;
    return out;
}

