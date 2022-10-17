#include "queue.h"

template<class T>
Queue<T>::Queue() {
    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;
}
template<class T>
Queue<T>::Queue(const Queue<T> &obj) {
    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;
    Node<T> * temp = obj.m_head;
    while (temp) {
        enqueue(*temp->data);
        temp = temp->next;
    }
}
template<class T>
Queue<T>::~Queue() {
    while (!is_empty()) {
        dequeue();
    }
}

template<class T>
Queue<T> & Queue<T>::operator=(const Queue<T> &obj) {
    if (this != &obj) {
        while (!is_empty()) {
            dequeue();
        }
        Node<T> * temp = obj.m_head;
        while (temp) {
            enqueue(*temp->data);
            temp = temp->next;
        }
    }
    return *this;
}

template<class T>
std::ostream & operator<<(std::ostream &out, const Queue<T> &obj) {
    Node<T> * temp = obj.m_head;

    std::cout << "Queue length: " << obj.m_size << std::endl;

    while (temp) {
        out << *temp->data << std::endl;
        temp = temp->next;
    }
    return out;
}

template<class T>
void Queue<T>::enqueue(const T &obj) {
    Node<T> * temp = new Node<T>(obj);
    if (is_empty()) {
        m_head = temp;
        m_tail = temp;
    }
    else {
        m_tail->next = temp;
        m_tail = temp;
    }
    temp->next = m_head;
    m_size ++;
}

template<class T>
T Queue<T>::dequeue() {
    if (is_empty()) {
        throw "Queue is empty";
    }

    Node<T> * temp = m_head;
    T data = *temp->data; // copy assignment operator
    m_head = m_head->next;
    m_tail->next = m_head;
    delete temp;
    temp = nullptr;
    m_size --;

    return data;
}

template<class T>
bool Queue<T>::is_empty() const {
    return m_size == 0;
}

template<class T>
T Queue<T>::peek() const {
    if (is_empty()) {
        throw "Queue is empty";
    }
    return *m_head->data;
}

template<class T>
void Queue<T>::display() const {
    std::cout << *this;
}
