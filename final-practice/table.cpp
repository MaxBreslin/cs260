#include "table.h"

//Please put the impelementation of the required functions here
int numberOfNodes(node * root) {
    if (!root) {
        return 0;
    }

    return 1 + numberOfNodes(root->left) + numberOfNodes(root->right);
}
void removeSmallest(node *& root) {
    if (!root->left) {
        delete root;
        root = nullptr;
    }
    else {
        removeSmallest(root->left);
    }
}

node * least_node(node * root) {
    if (!root->left) {
        return root;
    }

    return least_node(root->left);
}

node * removeEven(node * root, int &count) {
    if (!root) {
        return nullptr;
    }

    root->left = removeEven(root->left, count);
    root->right = removeEven(root->right, count);

    if (root->data % 2 == 0) {
        if (root->left && root->right) {
            node * least = least_node(root->right);

            root->data = least->data;
            least->data = 0;
            root->right = removeEven(root->right, count);
        }
        else {
            node * temp = root;

            if (root->left || root->right) {
                root = root->left ? root->left : root->right;
            }
            else {
                root = nullptr;
            }

            delete temp;
            count ++;
        }
    }
    
    return root;
}

int removeEven(node *& root) {
    int count = 0;
    root = removeEven(root, count);
    return count;
}
