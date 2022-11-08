#include "dlist.h"
using namespace std;

int main()
{
    node * head = NULL;
    build(head);
    display(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    cout << "There are " << countEven(head) << " even nodes" << endl;
    cout << removeEven(head) << " nodes have been removed" << endl;

    display(head);
    destroy(head);    
    return 0;
}
