#pragma once

#include "list.hpp"
#include <iostream>

template<class K, class V>
struct RedBlackTreeNode {
    RedBlackTreeNode();
    RedBlackTreeNode(const K &, const V &);
    ~RedBlackTreeNode();

    RedBlackTreeNode & operator=(const RedBlackTreeNode<K, V> &);

    template<class kK, class vV>
    friend std::ostream & operator<<(std::ostream &, const RedBlackTreeNode<kK, vV> &);

    K * key;
    V * value;
    bool color;

    RedBlackTreeNode<K, V> * left;
    RedBlackTreeNode<K, V> * right;
};

template<class K, class V>
RedBlackTreeNode<K, V>::RedBlackTreeNode() {
    key = nullptr;
    value = nullptr;
    color = 1;

    left = nullptr;
    right = nullptr;
}

template<class K, class V>
RedBlackTreeNode<K, V>::RedBlackTreeNode(const K &key, const V &value) {
    this->key = new K(key);
    this->value = new V(value);
    color = 1;

    left = nullptr;
    right = nullptr;
}

template<class K, class V>
RedBlackTreeNode<K, V>::~RedBlackTreeNode() {
    delete key;
    delete value;
    key = nullptr;
    value = nullptr;
    color = 0;

    left = nullptr;
    right = nullptr;
}

template<class K, class V>
RedBlackTreeNode<K, V> & RedBlackTreeNode<K, V>::operator=(const RedBlackTreeNode<K, V> &obj) {
    if (this != &obj) {
        delete key;
        delete value;
        key = new K(*obj.key);
        value = new V(*obj.value);
        color = obj.color;

        left = obj.left;
        right = obj.right;
    }
    return this;
}

template<class K, class V>
std::ostream & operator<<(std::ostream &out, const RedBlackTreeNode<K, V> &obj) {
    out << *obj.value;
    return out;
}

