#pragma once

#include "node.h"

template<class K, class V>
class Table {
public:
    Table();
    Table(size_t);
    Table(const Table<K, V> &);
    ~Table();

    Table & operator=(const Table<K, V> &);

    template<class kK, class vV>
    friend std::ostream & operator<<(std::ostream &, const Table<kK, vV> &);

    void set_hash_function(unsigned int (*)(const K &));
    unsigned int hash(const K &) const;

    void insert(const K &, const V &);
    V remove(const K &);
    V retreive(const K &) const;
    void display() const;

private:
    unsigned int (*m_hasher)(const K &);

    Node<K, V> ** m_table; // array of type Node<K> *
    size_t m_size;

    static const size_t DEFAULT_SIZE = 101;
};

template<class K, class V>
Table<K, V>::Table() {
    m_hasher = nullptr;
    m_size = DEFAULT_SIZE;
    m_table = new Node<K, V> *[m_size];

    for (size_t i = 0; i < m_size; i ++) {
        m_table[i] = nullptr;
    }
}
template<class K, class V>
Table<K, V>::Table(size_t size) {
    m_hasher = nullptr;
    m_size = size;
    m_table = new Node<K, V> *[m_size];

    for (size_t i = 0; i < m_size; i ++) {
        m_table[i] = nullptr;
    }
}
template<class K, class V>
Table<K, V>::Table(const Table<K, V> &obj) {
    m_hasher = obj.m_hasher;
    m_size = obj.m_size;

    m_table = new Node<K, V> *[m_size];
    for (size_t i = 0; i < m_size; i ++) {
        m_table[i] = obj.m_table[i];
    }
}
template<class K, class V>
Table<K, V>::~Table() {
    Node<K, V> * curr = nullptr;
    Node<K, V> * temp = nullptr;
    for (size_t i = 0; i < m_size; i ++) {
        curr = m_table[i];
        if (curr) {
            while (curr) {
                temp = curr;
                curr = curr->next;
                delete temp;
            }
        }
    }
    delete [] m_table;
    m_table = nullptr;
    m_hasher = nullptr;
    m_size = 0;
}

template<class K, class V>
Table<K,V> & Table<K, V>::operator=(const Table<K, V> &obj) {
    if (this != &obj) {
        delete [] m_table;
        m_hasher = obj.m_hasher;
        m_size = obj.m_size;

        m_table = new Node<K, V> *[m_size];
        for (size_t i = 0; i < m_size; i ++) {
            m_table[i] = obj.m_table[i];
        }
    }
    return *this;
}

template<class K, class V>
std::ostream & operator<<(std::ostream &out, const Table<K, V> &obj) {
    Node<K, V> * temp = nullptr;
    for (size_t i = 0; i < obj.m_size; i ++) {
        out << "[" << i << "]";

        temp = obj.m_table[i];
        if (temp) {
            while (temp) {
                out << " -> " << *temp->value;
                temp = temp->next;
            }
        }

        out << std::endl;
    }
    return out;
}

template<class K, class V>
void Table<K, V>::set_hash_function(unsigned int (*hash)(const K &)) {
    m_hasher = hash;
}

template<class K, class V>
unsigned int Table<K, V>::hash(const K & key) const {
    if (!m_hasher) {
        throw "Hash function not set";
    }

    return m_hasher(key) % m_size;
}

template<class K, class V>
void Table<K, V>::insert(const K &key, const V &value) {
    if (!m_hasher) {
        throw "Hash function not set";
    }

    Node<K, V> * head = new Node<K, V>(key, value);
    unsigned int index = hash(key);
    Node<K, V> * temp = m_table[index];

    m_table[index] = head;
    head->next = temp;
}

template<class K, class V>
V Table<K, V>::remove(const K &key) {
    if (!m_hasher) {
        throw "Hash function not set";
    }

    unsigned int index = hash(key);
    Node<K, V> * curr = m_table[index];
    Node<K, V> * prev = m_table[index];

    if (!curr) {
        throw "Value not found";
    }

    if (*curr->key == key) {
        V temp = *curr->value;

        m_table[index] = curr->next;
        delete curr;
        
        return temp;
    }

    curr = curr->next;

    while (*curr->key != key) {
        prev = curr;
        curr = curr->next;
        if (!curr) {
            throw "Value not found";
        }
    }

    V temp = *curr->value;

    prev->next = curr->next;
    delete curr;

    return temp;
}

template<class K, class V>
V Table<K, V>::retreive(const K &key) const {
    if (!m_hasher) {
        throw "Hash function not set";
    }

    unsigned int index = hash(key);
    Node<K, V> * temp = m_table[index];
    
    if (!temp) {
        return nullptr;
    }

    while (*temp->key != key) {
        temp = temp->next;
        if (!temp) {
            throw "Value not found";
        }
    }

    return *temp->value;
}

template<class K, class V>
void Table<K, V>::display() const {
    std::cout << *this;
}
