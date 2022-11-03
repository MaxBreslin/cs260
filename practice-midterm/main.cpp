#include "dlist.h"
using namespace std;

int main()
{
    node * head = NULL;
    build(head);
    display(head);

    cout << "Item count: " << count(head) << endl;
    cout << "Inserting 5 at position 3..." << endl;
    insert(head, 5 , 3);
    cout << "List after insertion:" << endl;
    display(head);
    cout << "Inserting 10 at position 0..." << endl;
    insert(head, 10 , 0);
    cout << "List after insertion:" << endl;
    display(head);
    cout << "Integer at position 1 removed: " << remove(head, 1) << endl;
    cout << "List after removal:" << endl;
    display(head);
    cout << "Integer at position 0 removed: " << remove(head, 0) << endl;
    cout << "List after removal:" << endl;
    display(head);

    display(head);
    destroy(head);
    return 0;
}
