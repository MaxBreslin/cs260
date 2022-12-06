#include "table.h"

#include <iostream>

using namespace std;

int main()
{
    node * root = NULL;
    build(root);
    display(root);

    /*  PLACE YOUR FUNCTION CALL HERE */
    cout << "Sum of even nodes: " << sumOfEvenNodes(root) << endl;
    
    node * newRoot = nullptr;
    cout << "Copying non-leaf nodes from root to newRoot..." << endl;
    copyNonLeaf(root, newRoot);

    cout << "New tree: " << endl;
    display(newRoot);
    destroy(newRoot);

    display(root);
    destroy(root);

    return 0;
}
