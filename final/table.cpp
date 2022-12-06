#include "table.h"

//Please put the impelementation of the required functions here
int sumOfEvenNodes(node * root) {
    if (!root) {
        return 0;
    }

    if (root->data % 2 == 0) {
        return root->data + sumOfEvenNodes(root->left) + sumOfEvenNodes(root->right);
    }
    return sumOfEvenNodes(root->left) + sumOfEvenNodes(root->right);
}

void copyNonLeaf(node * root, node *& newRoot) {
    newRoot = copyToNewRoot(root, newRoot);
}

node * copyToNewRoot(node * root, node * newRoot) {
    // If root is null or a leaf
    if (!root || !(root->left || root->right)) {
        return nullptr;
    }

    if (!newRoot) {
        newRoot = new node;
        newRoot->left = nullptr;
        newRoot->right = nullptr;
    }

    newRoot->data = root->data;
    newRoot->left = copyToNewRoot(root->left, newRoot->left);
    newRoot->right = copyToNewRoot(root->right, newRoot->right);

    return newRoot;
}
