#include "table.h"

int count(node * root) {
    if (!root) {
        return 0;
    }

    return 1 + count(root->left) + count(root->right);
}

int sum(node * root) {
    if (!root) {
        return 0;
    }

    return root->data + sum(root->left) + sum(root->right);
}

int height(node * root) {
    if (!root) {
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    return left > right ? left + 1 : right + 1;
}
