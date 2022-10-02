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

	friend std::ostream& operator<<(std::ostream& out, const LinkedList& list);

private:
	struct Node {
		Node() {
			next = prev = nullptr;
			data = '\0';
		}
		Node(const char ch) {
			next = prev = nullptr;
			data = ch;
		}
		~Node() {
			next = prev = nullptr;
			data = '\0';
		}
		char data;
		Node * next;
		Node * prev;
	};

	Node * head;
	Node * tail;
	int size;
};

#endif // _LINKED_LIST_
