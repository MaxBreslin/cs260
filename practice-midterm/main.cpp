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
    // cout << "Integer at position 3 removed: " << remove(head, 0) << endl;



    display(head);
    destroy(head);
    return 0;
}
