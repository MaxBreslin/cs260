#include "table.h"

#include <iostream>

using namespace std;

int main()
{
    node * root = NULL;
    build(root);
    display(root);

    /*  PLACE YOUR FUNCTION CALL HERE */
    cout << "Count: " << count(root) << endl;
    cout << "Sum: " << sum(root) << endl;
    cout << "Height: " << height(root) << endl;


    display(root);
    destroy(root);
    return 0;
}
