#include "dlist.h"

//put the implmenetation of the required functions here
int count(node * head) {
    if (!head) {
        return 0;
    }
    return 1 + count(head->next);
}

void insert(node * & head, int newInt, int position) {
    if (!head) {
        return;
    }
    if (position == 0) {
        node * temp = new node;
        temp->data = newInt;
        head->previous->next = temp;
        temp->previous = head->previous;
        temp->next = head;
        head->previous = temp;
        return;
    }
    return insert(head->next, newInt, position - 1);
}

int remove(node * & head, int position) {
    if (!head) {
        return -1;
    }
    if (position == 0) {
        int data = head->data;

        if (head->previous) {
            head->previous->next = head->next;
        }
        if (head->next) {
            head->next->previous = head->previous;
        }

        delete head;
        return data;
    }
    return remove(head->next, position - 1);
}
