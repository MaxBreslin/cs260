#include "linkedlist.h"

LinkedList::LinkedList() {
    head = tail = nullptr;
    size = 0;
}

LinkedList::~LinkedList() {
    Node * curr = head;
    while (curr) {
        head = head->next;
        delete curr;
        curr = head;
    }

    head = tail = nullptr;
}

void LinkedList::add(char ch) {
    Node * curr = new Node(ch);
    if (tail) {
        tail->next = curr;
        curr->prev = tail;
        tail = curr;
    }
    else {
        head = tail = curr;
    }
    size ++;
}

bool LinkedList::find(char ch) {
    Node * curr = head;
    while (curr) {
        if (curr->data == ch) {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

bool LinkedList::del(char ch) {
    Node * curr = head;
    while (curr) {
        if (curr->data == ch) {
            if (curr->prev) {
                curr->prev->next = curr->next;
            }
            else {
                head = curr->next;
            }
            if (curr->next) {
                curr->next->prev = curr->prev;
            }
            else {
                tail = curr->prev;
            }
            delete curr;
            size --;
            return true;
        }
        curr = curr->next;
    }
    return false;
}

std::ostream& operator<<(std::ostream& out, const LinkedList& list) {
    LinkedList::Node * curr = list.head;
    while (curr) {
        out << curr->data << " ";
        curr = curr->next;
    }
    out << std::endl;
    return out;
}
