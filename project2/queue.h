#pragma once

#include "node.h"

template<class T>
class Queue {
public:
    Queue();
    Queue(const Queue<T> &);
    ~Queue();

    Queue & operator=(const Queue<T> &);
    friend std::ostream & operator<<(std::ostream &, const Queue<T> &);

    void enqueue(const T &);
    T dequeue();
    bool is_empty() const;
    T peek() const;
    void display() const;
private:
    Node<T> * m_head;
    Node<T> * m_tail;
    size_t m_size;
};