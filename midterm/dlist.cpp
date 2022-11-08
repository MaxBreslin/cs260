#include "dlist.h"

//put the implmenetation of the required functions here
int countEven(node * head) {
    if (!head) {
        return 0;
    }
    if (head->data % 2 == 1) {
        return countEven(head->next);
    }
    return 1 + countEven(head->next);
}

int removeEven(node *& head) {
    if (!head) {
        return 0;
    }
    if (head->data % 2 == 0) {
        node * del = head;
        node * curr = head->next;
        node * prev = head->previous;
        
        if (curr) {
            curr->previous = prev;
        }
        if (prev) {
            prev->next = curr;
        }
        
        head = curr;
        
        delete del;
        return 1 + removeEven(head);
    }
    return removeEven(head->next);
}
