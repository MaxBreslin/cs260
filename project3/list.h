#pragma once

// list.h - List template class declaration and implementation (linear linked list)

#include "listnode.h"

template<class T>
class List {
public:
    List();
    List(const List &);
    ~List();

    List & operator=(const List &);

    template<class tT>
    friend std::ostream & operator<<(std::ostream &, const List<tT> &);

    // Returns the element at the passed index
    T operator[](size_t) const;

    // Inserts the passed element at the front of the list
    void insert(const T &);

    // Removes all elements in the list with the passed value and returns a list
    // of the values that were removed
    List<T> remove(const T &);

    // Displays the list
    void display() const;

    // Returns the number of elements in the list
    size_t length() const;

private:
    ListNode<T> * m_head;
    size_t m_size;
};

template<class T>
List<T>::List() {
    m_head = nullptr;
    m_size = 0;
}
template<class T>
List<T>::List(const List &obj) {
    m_head = nullptr;
    m_size = 0;

    ListNode<T> * curr = obj.m_head;
    while (curr) {
        insert(*curr->data);
        curr = curr->next;
    }
}
template<class T>
List<T>::~List() {
    ListNode<T> * curr = m_head;
    while (curr) {
        ListNode<T> * temp = curr;
        curr = curr->next;
        delete temp;
    }
    m_head = nullptr;
    m_size = 0;
}

template<class T>
List<T> & List<T>::operator=(const List &obj) {
    if (this != &obj) {
        ListNode<T> * curr = m_head;
        ListNode<T> * temp = curr;
        
        while (curr) {
            temp = curr;
            curr = curr->next;
            delete temp;
        }
        m_head = nullptr;
        m_size = 0;

        curr = obj.m_head;
        while (curr) {
            insert(*curr->data);
            curr = curr->next;
        }
    }
    return *this;
}

template<class T>
std::ostream & operator<<(std::ostream &out, const List<T> &obj) {
    ListNode<T> * curr = obj.m_head;
    int i = 1;
    while (curr) {
        out << i ++ << ": " << *curr->data << std::endl;
        curr = curr->next;
    }
    return out;
}

template<class T>
T List<T>::operator[](size_t index) const {
    if (index >= m_size) {
        throw "Index out of range";
    }
    ListNode<T> * curr = m_head;
    for (size_t i = 0; i < index; i ++) {
        curr = curr->next;
    }
    return *curr->data;
}

template<class T>
void List<T>::insert(const T &data) {
    ListNode<T> * node = new ListNode<T>(data);
    
    node->next = m_head;
    m_head = node;

    m_size ++;
}

template<class T>
List<T> List<T>::remove(const T &data) {
    ListNode<T> * curr = m_head;
    ListNode<T> * prev = nullptr;
    ListNode<T> * temp = nullptr;
    List<T> removed;

    while (curr) {
        if (*curr->data == data) {
            temp = curr;
            if (prev) {
                prev->next = curr->next;
            }
            else {
                m_head = curr->next;
            }
            curr = curr->next;
            removed.insert(*temp->data);
            delete temp;
            m_size --;
        }
        else {
            prev = curr;
            curr = curr->next;
        }
    }
}

template<class T>
void List<T>::display() const {
    std::cout << *this << std::endl;
}

template<class T>
size_t List<T>::length() const {
    return m_size;
}
