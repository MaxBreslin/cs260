#include "dlist.h"
using namespace std;

int main()
{
    node * head = NULL;
    build(head);
    display(head);

    cout << "Item count: " << count(head) << endl;
    // cout << "Inserting 5 at position 5..." << endl;
    // insert(head, 5 , 5);
    cout << "Integer at position 3 removed: " << remove(head, 3) << endl;



    display(head);
    destroy(head);
    return 0;
}
