#pragma once

// table.h - Table template class declaration and implementation

#include "tablenode.h"
#include "list.h"

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

    // Sets m_hasher to the passed function pointer - MUST be called before
    // any other methods are usable
    void set_hash_function(unsigned int (*)(const K &));

    // Calls m_hasher on the passed key and returns the result
    unsigned int hash(const K &) const;

    // Inserts the passed key-value pair into the table
    void insert(const K &, const V &);

    // Removes every node in the table with the passed key and returns a list
    // of the values that were removed
    List<V> remove(const K &);

    // Returns a list of all values in the table with the passed key
    List<V> retrieve(const K &) const;

    // Replaces the value of the node with the passed key with the passed value
    void edit(const K &, const V &, const V &);

    // Displays the hash table
    void display() const;

private:
    unsigned int (*m_hasher)(const K &);

    TableNode<K, V> ** m_table; // array of type TableNode<K> *
    size_t m_size;

    static const size_t DEFAULT_SIZE = 101;
};

template<class K, class V>
Table<K, V>::Table() {
    m_hasher = nullptr;
    m_size = DEFAULT_SIZE;
    m_table = new TableNode<K, V> *[m_size];

    for (size_t i = 0; i < m_size; i ++) {
        m_table[i] = nullptr;
    }
}
template<class K, class V>
Table<K, V>::Table(size_t size) {
    m_hasher = nullptr;
    m_size = size;
    m_table = new TableNode<K, V> *[m_size];

    for (size_t i = 0; i < m_size; i ++) {
        m_table[i] = nullptr;
    }
}
template<class K, class V>
Table<K, V>::Table(const Table<K, V> &obj) {
    m_hasher = obj.m_hasher;
    m_size = obj.m_size;
    m_table = new TableNode<K, V> *[m_size];

    for (size_t i = 0; i < m_size; i ++) {
        m_table[i] = obj.m_table[i];
    }
}
template<class K, class V>
Table<K, V>::~Table() {
    TableNode<K, V> * curr = nullptr;
    TableNode<K, V> * temp = nullptr;

    for (size_t i = 0; i < m_size; i ++) {
        curr = m_table[i];
        while (curr) {
            temp = curr;
            curr = curr->next;
            delete temp;
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
        TableNode<K, V> * curr = nullptr;
        TableNode<K, V> * temp = nullptr;

        for (size_t i = 0; i < m_size; i ++) {
            curr = m_table[i];
            while (curr) {
                temp = curr;
                curr = curr->next;
                delete temp;
            }
        }
        delete [] m_table;

        m_hasher = obj.m_hasher;
        m_size = obj.m_size;
        m_table = new TableNode<K, V> *[m_size];

        for (size_t i = 0; i < m_size; i ++) {
            m_table[i] = obj.m_table[i];
        }
    }
    return *this;
}

template<class K, class V>
std::ostream & operator<<(std::ostream &out, const Table<K, V> &obj) {
    TableNode<K, V> * temp = nullptr;
    for (size_t i = 0; i < obj.m_size; i ++) {
        out << "[" << i << "]";

        temp = obj.m_table[i];
        if (temp) {
            while (temp) {
                out << " -> [" << *temp->value << "]";
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

    unsigned int index = hash(key);
    TableNode<K, V> * head = new TableNode<K, V>(key, value);
    TableNode<K, V> * temp = m_table[index];

    m_table[index] = head;
    head->next = temp;
}

template<class K, class V>
List<V> Table<K, V>::remove(const K &key) {
    if (!m_hasher) {
        throw "Hash function not set";
    }

    unsigned int index = hash(key);
    List<V> removed;
    TableNode<K, V> * curr = m_table[index];
    TableNode<K, V> * prev = nullptr;
    TableNode<K, V> * temp = nullptr;

    if (!curr) {
        return removed;
    }

    while (curr) {
        if (*curr->key == key) {
            temp = curr;
            removed.insert(*curr->value);
            if (prev) {
                prev->next = curr->next;
            }
            else {
                m_table[index] = curr->next;
            }
            curr = curr->next;
            delete temp;
        }
        else {
            prev = curr;
            curr = curr->next;
        }
    }
    return removed;
}

template<class K, class V>
List<V> Table<K, V>::retrieve(const K &key) const {
    if (!m_hasher) {
        throw "Hash function not set";
    }

    unsigned int index = hash(key);
    List<V> retrieved;
    TableNode<K, V> * curr = m_table[index];

    while (curr) {
        if (*curr->key == key) {
            retrieved.insert(*curr->value);
        }
        curr = curr->next;
    }

    return retrieved;
}

template<class K, class V>
void Table<K, V>::edit(const K &key, const V &value, const V &new_value) {
    if (!m_hasher) {
        throw "Hash function not set";
    }

    unsigned int index = hash(key);
    TableNode<K, V> * curr = m_table[index];

    while (curr) {
        if (*curr->key == key && *curr->value == value) {
            delete curr->value;
            curr->value = new V(new_value);
        }
        curr = curr->next;
    }
}

template<class K, class V>
void Table<K, V>::display() const {
    std::cout << *this;
}
