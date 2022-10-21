#ifndef _LINKED_LIST_
#define _LINKED_LIST_

#include <ostream>

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();

    void add(char ch);
    bool find(char ch);
    bool del(char ch);

    friend std::ostream& operator<<(std::ostream& out, LinkedList& list);
private:
    struct Node {
        Node(char ch, Node * next = nullptr) {
            m_ch = ch;
            m_next = next;
        }
        char m_ch;
        Node * m_next;
    };
    Node * m_head;

    Node * add(Node *, char);
    bool find(Node *, char);
    bool del(Node *, char);
};

LinkedList::LinkedList() {
    m_head = nullptr;
}
LinkedList::~LinkedList() {
    Node * temp = m_head;
    while (m_head) {
        m_head = m_head->m_next;
        delete temp;
        temp = m_head;
    }
}

void LinkedList::add(char ch) {
    m_head = add(m_head, ch);
}

bool LinkedList::find(char ch) {
    return find(m_head, ch);
}

bool LinkedList::del(char ch) {
    return del(m_head, ch);
}

std::ostream& operator<<(std::ostream& out, LinkedList& list) {
    LinkedList::Node * temp = list.m_head;
    while (temp) {
        out << temp->m_ch << " ";
        temp = temp->m_next;
    }
    out << std::endl;
    return out;
}

LinkedList::Node * LinkedList::add(Node * curr, char ch) {
    if (!curr || curr->m_ch > ch) {
        return new Node(ch, curr);
    }
    curr->m_next = add(curr->m_next, ch);
    return curr;
}

bool LinkedList::find(Node * curr, char ch) {
    if (!curr) {
        return false;
    }
    if (curr->m_ch == ch) {
        return true;
    }
    return find(curr->m_next, ch);
}

bool LinkedList::del(Node * curr, char ch) {
    if (!curr) {
        return false;
    }
    if (curr->m_ch == ch) {
        Node * temp = curr->m_next;
        delete curr;
        m_head = temp;
        return true;
    }
    if (curr->m_next && curr->m_next->m_ch == ch) {
        Node * temp = curr->m_next->m_next;
        delete curr->m_next;
        curr->m_next = temp;
        return true;
    }
    return del(curr->m_next, ch);
}

#endif // _LINKED_LIST_
