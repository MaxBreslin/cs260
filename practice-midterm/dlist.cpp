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

        temp->previous = nullptr;
        temp->next = head;
        head->previous = temp;
        head = temp;
        return;
    }
    if (position == 1) {
        node * temp = new node;
        temp->data = newInt;

        temp->previous = head;
        temp->next = head->next;
        
        head->next->previous = temp;
        head->next = temp;

        return;
    }
    insert(head->next, newInt, position - 1);
}

int remove(node * & head, int position) {
    if (!head) {
        return -1;
    }
    if (position == 0) {
        node * temp = head;
        int data = head->data;

        head->next->previous = nullptr;
        head = head->next;

        delete temp;
        return data;
    }
    if (position == 1) {
        node * temp = head->next;
        int data = temp->data;

        head->next = temp->next;
        temp->next->previous = head;

        delete temp;
        return data;
    }
    return remove(head->next, position - 1);
}
