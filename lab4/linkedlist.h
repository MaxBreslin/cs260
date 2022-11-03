#ifndef _LINKED_LIST_
#define _LINKED_LIST_

#include <ostream>

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();

    void add(int data);
    bool find(int data);
    bool del(int data);

	int sum();
	int sumR();

    friend std::ostream& operator<<(std::ostream& out, LinkedList& list);
private:
    struct Node {
        Node(int data, Node * next = nullptr) {
            m_data = data;
            m_next = next;
        }
        int m_data;
        Node * m_next;
    };
    Node * m_head;

    Node * add(Node *, int);
    bool find(Node *, int);
    bool del(Node *, int);

	int sumR(Node *);
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

void LinkedList::add(int data) {
    m_head = add(m_head, data);
}

bool LinkedList::find(int data) {
    return find(m_head, data);
}

bool LinkedList::del(int data) {
    return del(m_head, data);
}

std::ostream& operator<<(std::ostream& out, LinkedList& list) {
    LinkedList::Node * temp = list.m_head;
    while (temp) {
        out << temp->m_data << " ";
        temp = temp->m_next;
    }
    out << std::endl;
    return out;
}

LinkedList::Node * LinkedList::add(Node * curr, int data) {
    if (!curr || curr->m_data > data) {
        return new Node(data, curr);
    }
    curr->m_next = add(curr->m_next, data);
    return curr;
}

bool LinkedList::find(Node * curr, int data) {
    if (!curr) {
        return false;
    }
    if (curr->m_data == data) {
        return true;
    }
    return find(curr->m_next, data);
}

bool LinkedList::del(Node * curr, int data) {
    if (!curr) {
        return false;
    }
    if (curr->m_data == data) {
        Node * temp = curr->m_next;
        delete curr;
        m_head = temp;
        return true;
    }
    if (curr->m_next && curr->m_next->m_data == data) {
        Node * temp = curr->m_next->m_next;
        delete curr->m_next;
        curr->m_next = temp;
        return true;
    }
    return del(curr->m_next, data);
}

int LinkedList::sum() {
	int sum = 0;
	Node * curr = m_head;

	while (curr) {
		sum += curr->m_data;
		curr = curr->m_next;
	}

	return sum;
}

int LinkedList::sumR() {
	return sumR(m_head);
}
int LinkedList::sumR(Node * curr) {
	if (!curr) {
		return 0;
	}
	return curr->m_data + sumR(curr->m_next);
}


#endif // _LINKED_LIST_
