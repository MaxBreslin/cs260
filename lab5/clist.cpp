#include "clist.h"
// Write your functions in this file.
int count(node * head) {
    if (!head) {
        return 0;
    }

    int count = 0;
    node * temp = head;

    do {
        temp = temp->next;
        count ++;
    }
    while (temp != head);

    return count;
}

int countR(node * head) {
    static node * head_ptr = head;

    if (head->next == head_ptr) {
        return 1;
    }

    return 1 + countR(head->next);
}

int sum(node * head) {
    if (!head) {
        return 0;
    }

    int sum = 0;
    node * temp = head;
    do {
        sum += temp->data;
        temp = temp->next;
    }
    while (temp != head);

    return sum;
}

int sumR(node * head) {
    static node * head_ptr = head;

    if (head->next == head_ptr) {
        return head->next->data;
    }

    return head->data + sumR(head->next);
}
