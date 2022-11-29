#pragma once

// avltree.hpp - AVLTree template class declaration and implementation

#include "avltreenode.hpp"

template<class K, class V>
class AVLTree {
public:
    AVLTree();
    AVLTree(const AVLTree<K, V> &);
    ~AVLTree();

    AVLTree & operator=(const AVLTree<K, V> &);

    template<class kK, class vV>
    friend std::ostream & operator<<(std::ostream &, const AVLTree<kK, vV> &);

    // Returns the height of the tree
    size_t height() const;
    
    // Returns the max width of the tree
    size_t max_width() const;

    // Inserts the passed key-value pair into the tree
    // If the key already exists, the value is updated
    void insert(const K &, const V &);

    // Removes the node with the passed key from the tree
    // and returns the value associated with that key
    // Throws an exception if the key is not found
    V remove(const K &);

    // Returns the value associated with the passed key
    // Throws an exception if the key is not found
    V retrieve(const K &) const;

    // Returns a list of all values in the tree,
    // sorted by key
    List<V> retrieve_all() const;

    // Displays the tree in a graphical format
    void display() const;
    
private:
    // Recursive helper functions
    size_t height(AVLTreeNode<K, V> *) const;
    size_t width(AVLTreeNode<K, V> *, unsigned int) const;
    AVLTreeNode<K, V> * insert(const K &, const V &, AVLTreeNode<K, V> *);
    AVLTreeNode<K, V> * remove(const K &, AVLTreeNode<K, V> *);
    V retrieve(const K &, AVLTreeNode<K, V> *) const;

    // Returns height of the passed root's left subtree minus
    // the height of the passed root's right subtree
    int balance_factor(AVLTreeNode<K, V> *) const;

    // Returns a list of nodes at the passed level in the tree
    // Used ONLY by display()
    List<AVLTreeNode<K, V> *> level(unsigned int) const;
    void level(unsigned int, AVLTreeNode<K, V> *, List<AVLTreeNode<K, V> *> &) const;

    // Returns the left-most node from the passed root
    AVLTreeNode<K, V> * least_node(AVLTreeNode<K, V> *) const;

    // Returns the passed root after balancing it
    AVLTreeNode<K, V> * balance_node(AVLTreeNode<K, V> *);

    // Traversals that return a list of pointers to nodes
    List<AVLTreeNode<K, V> *> inorder_traversal() const;
    void inorder_traversal(AVLTreeNode<K, V> *, List<AVLTreeNode<K, V> *> &) const;

    List<AVLTreeNode<K, V> *> preorder_traversal() const;
    void preorder_traversal(AVLTreeNode<K, V> *, List<AVLTreeNode<K, V> *> &) const;

    List<AVLTreeNode<K, V> *> postorder_traversal() const;
    void postorder_traversal(AVLTreeNode<K, V> *, List<AVLTreeNode<K, V> *> &) const;

    // Rotates the passed root and returns the new root
    AVLTreeNode<K, V> * ll_rotation(AVLTreeNode<K, V> *);
    AVLTreeNode<K, V> * rr_rotation(AVLTreeNode<K, V> *);
    AVLTreeNode<K, V> * rl_rotation(AVLTreeNode<K, V> *);
    AVLTreeNode<K, V> * lr_rotation(AVLTreeNode<K, V> *);

    AVLTreeNode<K, V> * m_root;
    size_t m_size;
};

template<class K, class V>
AVLTree<K, V>::AVLTree() {
    m_root = nullptr;
    m_size = 0;
}

template<class K, class V>
AVLTree<K, V>::AVLTree(const AVLTree<K, V> &obj) {
    List<AVLTreeNode<K, V> *> nodes = obj.preorder_traversal();
    m_size = obj.m_size;

    for (size_t i = 0; i < m_size; i ++) {
        insert(nodes[i]);
    }
}

template<class K, class V>
AVLTree<K, V>::~AVLTree() {
    List<AVLTreeNode<K, V> *> nodes = postorder_traversal();

    for (size_t i = 0; i < m_size; i ++) {
        delete nodes[i];
    }

    m_root = nullptr;
    m_size = 0;
}

template<class K, class V>
AVLTree<K, V> & AVLTree<K, V>::operator=(const AVLTree<K, V> &obj) {
    if (this != &obj) {
        List<AVLTreeNode<K, V> *> nodes = postorder_traversal();

        for (size_t i = 0; i < m_size; i ++) {
            delete nodes[i];
        }

        m_root = nullptr;
        m_size = 0;

        List<AVLTreeNode<K, V> *> new_nodes = obj.preoder_traversal();
        for (size_t i = 0; i < obj.m_size; i ++) {
            insert(new_nodes[i]->key, new_nodes[i]->value);
        }
    }
    return *this;
}

template<class K, class V>
std::ostream & operator<<(std::ostream &out, const AVLTree<K, V> &obj) {
    List<AVLTreeNode<K, V> *> nodes = obj.inorder_traversal();

    for (size_t i = 0; i < obj.m_size; i ++) {
        out << *nodes[i] << std::endl;
    }

    return out;
}

template<class K, class V>
size_t AVLTree<K, V>::height() const {
    return height(m_root);
}

template<class K, class V>
size_t AVLTree<K, V>::height(AVLTreeNode<K, V> * root) const {
    if (!root) {
        return 0;
    }

    size_t left_height = height(root->left);
    size_t right_height = height(root->right);
    return left_height > right_height ? left_height + 1 : right_height + 1;
}

template<class K, class V>
size_t AVLTree<K, V>::max_width() const {
    size_t max_width = 0;
    size_t w = 0;
    size_t h = height(m_root);
 
    for (size_t i = 0; i < h; i ++) {
        w = width(m_root, i);
        max_width = max_width > w ? max_width : w;
    }
 
    return max_width;
}
template<class K, class V>
size_t AVLTree<K, V>::width(AVLTreeNode<K, V> * root, unsigned int l) const {
    if (!root) {
        return 0;
    }

    if (l == 0) {
        return 1;
    }

    return width(root->left, l - 1) + width(root->right, l - 1);
}

template<class K, class V>
int AVLTree<K, V>::balance_factor(AVLTreeNode<K, V> * root) const {
    if (!root) {
        return 0;
    }

    return height(root->left) - height(root->right);
}

template<class K, class V>
List<AVLTreeNode<K, V> *> AVLTree<K, V>::level(unsigned int l) const {
    if (l >= height()) {
        throw "Level out of range";
    }
    List<AVLTreeNode<K, V> *> nodes(width(m_root, l));
    
    level(l, m_root, nodes);

    return nodes;
}

// Fills the passed list with exactly 2^l nodes
// If there is no node at a location, nullptr is inserted
template<class K, class V>
void AVLTree<K, V>::level(unsigned int l, AVLTreeNode<K, V> * root, List<AVLTreeNode<K, V> *> &nodes) const {
    if (!l) {
        nodes.insert(root);
        return;
    }

    if (!root) {
        level(l - 1, nullptr, nodes);
        level(l - 1, nullptr, nodes);
    }
    else {
        level(l - 1, root->left, nodes);
        level(l - 1, root->right, nodes);
    }
}

template<class K, class V>
AVLTreeNode<K, V> * AVLTree<K, V>::least_node(AVLTreeNode<K, V> * root) const {
    if (!root->left) {
        return root;
    }

    return least_node(root->left);
}

template<class K, class V>
AVLTreeNode<K, V> * AVLTree<K, V>::balance_node(AVLTreeNode<K, V> * root) {
    if (!root) {
        return nullptr;
    }

    root->height = height(root);

    int root_bf = balance_factor(root);

    // Left subtree is heavier
    if (root_bf > 1) {
        // Left subtree is left heavy
        if (balance_factor(root->left) >= 0) {
            return ll_rotation(root);
        }
        // Left subtree is right heavy
        else {
            return lr_rotation(root);
        }
    }
    // Right subtree is heavier
    else if (root_bf < -1) {
        // Right subtree is left heavy
        if (balance_factor(root->right) > 0) {
            return rl_rotation(root);
        }
        // Right subtree is right heavy
        else {
            return rr_rotation(root);
        }
    }

    return root;
}

template<class K, class V>
void AVLTree<K, V>::insert(const K &key, const V &value) {
    m_root = insert(key, value, m_root);
}
template<class K, class V>
AVLTreeNode<K, V> * AVLTree<K, V>::insert(const K &key, const V &value, AVLTreeNode<K, V> * root) {
    if (!root) {
        m_size ++;
        return new AVLTreeNode<K, V>(key, value);
    }

    if (key < root->key) {
        root->left = insert(key, value, root->left);
    }
    else if (key > root->key) {
        root->right = insert(key, value, root->right);
    }
    else {
        root->value = value;
        return root;
    }

    return balance_node(root);
}

template<class K, class V>
V AVLTree<K, V>::remove(const K &key) {
    V value = retrieve(key);
    m_root = remove(key, m_root);
    return value;
}
template<class K, class V>
AVLTreeNode<K, V> * AVLTree<K, V>::remove(const K &key, AVLTreeNode<K, V> * root) {
    if (!root) {
        throw "Node with key not found";
    }

    if (key < root->key) {
        root->left = remove(key, root->left);
    }
    else if (key > root->key) {
        root->right = remove(key, root->right);
    }
    else {
        // Three possible cases:
        // 1. root is a leaf node
        // 2. root has one child
        // 3. root has two children

        // 3:
        if (root->left && root->right) {
            AVLTreeNode<K, V> * low_node = least_node(root->right);

            root->key = low_node->key;
            root->value = low_node->value;
            root->height = low_node->height;

            root->right = remove(low_node->key, root->right);
        }
        // 1 & 2:
        else {
            AVLTreeNode<K, V> * temp = root;

            // 2:
            if (root->left || root->right) {
                root = root->left ? root->left : root->right;
            }
            // 1:
            else {
                root = nullptr;
            }

            m_size --;
            delete temp;
        }
    }

    if (!root) {
        return nullptr;
    }

    return balance_node(root);
}

template<class K, class V>
V AVLTree<K, V>::retrieve(const K &key) const {
    return retrieve(key, m_root);
}

template<class K, class V>
V AVLTree<K, V>::retrieve(const K &key, AVLTreeNode<K, V> * root) const {
    if (!root) {
        throw "Node with key not found";
    }

    if (key < root->key) {
        return retrieve(key, root->left);
    }
    else if (key > root->key) {
        return retrieve(key, root->right);
    }
    else {
        return root->value;
    }
}

template<class K, class V>
List<V> AVLTree<K, V>::retrieve_all() const {
    List<AVLTreeNode<K, V> *> nodes = inorder_traversal();
    List<V> values(nodes.length());

    for (size_t i = 0; i < nodes.length(); i ++) {
        values.insert(nodes[i]->value);
    }

    return values;
}

template<class K, class V>
void AVLTree<K, V>::display() const {
    // THIS FUNCTION CURRENTLY ONLY WORKS FOR STRING KEYS DUE TO SPACING ISSUES
    if (typeid(K) != typeid(String)) {
        throw "This function is only implemented for String keys";
    }
    
    size_t h = height();

    List<List<AVLTreeNode<K, V> *>> levels;

    for (size_t i = 0; i < h; i ++) {
        levels.insert(level(i));
    }
    

    unsigned int pre_space = 0;
    unsigned int between_space = 0;
    unsigned int nodes_in_full_layer = 0; 

    for (size_t i = 0; i < h; i ++) {
        pre_space = pow(2, h - i) - 2;
        nodes_in_full_layer = pow(2, i);
        // between_space = ( total space - both pre spaces - space of all nodes in layer ) / ( number of between spaces needed )
        between_space = (4 * pow(2, h - 1) - 1 - 2 * pre_space - 3 * nodes_in_full_layer) / (nodes_in_full_layer - 1);

        if (between_space) {
            for (unsigned int j = 0; j < pre_space + 2; j ++) {
                std::cout << " ";
            }

            for (unsigned int j = 0; j < nodes_in_full_layer; j ++) {
                if (j % 2 == 1) {
                    for (unsigned int k = 0; k < between_space + 4; k ++) {
                        std::cout << " ";
                    }
                    continue;
                }
                if (levels[i][j] && levels[i][j + 1]) {
                    std::cout << "+";
                    for (unsigned int k = 0; k < between_space; k ++) {
                        std::cout << "-";
                    }
                    std::cout << "+";
                }
                else if (levels[i][j]) {
                    std::cout << "+";
                    for (unsigned int k = 0; k < between_space; k ++) {
                        std::cout << "-";
                    }
                    std::cout << " ";
                }
                else if (levels[i][j + 1]) {
                    std::cout << " ";
                    for (unsigned int k = 0; k < between_space; k ++) {
                        std::cout << "-";
                    }
                    std::cout << "+";
                }
                else {
                    for (unsigned int k = 0; k < between_space + 2; k ++) {
                        std::cout << " ";
                    }
                }
            }
            std::cout << std::endl;
        }

        for (unsigned int j = 0; j < pre_space; j ++) {
            std::cout << " ";
        }

        for (unsigned int j = 0; j < nodes_in_full_layer; j ++) {
            if (levels[i][j]) {
                std::cout << levels[i][j]->key.substring(0, 2);
            }
            else {
                std::cout << "   ";
            }

            for (unsigned int k = 0; k < between_space; k ++) {
                std::cout << " ";
            }
        }

        std::cout << std::endl;
    }
}

template<class K, class V>
List<AVLTreeNode<K, V> *> AVLTree<K, V>::inorder_traversal() const {
    List<AVLTreeNode<K, V> *> nodes(m_size);

    inorder_traversal(m_root, nodes);

    return nodes;
}
template<class K, class V>
void AVLTree<K, V>::inorder_traversal(AVLTreeNode<K, V> * root, List<AVLTreeNode<K, V> *> &nodes) const {
    if (!root) {
        return;
    }
    
    inorder_traversal(root->left, nodes);
    nodes.insert(root);
    inorder_traversal(root->right, nodes);
}

template<class K, class V>
List<AVLTreeNode<K, V> *> AVLTree<K, V>::preorder_traversal() const {
    List<AVLTreeNode<K, V> *> nodes(m_size);

    preorder_traversal(m_root, nodes);

    return nodes;
}
template<class K, class V>
void AVLTree<K, V>::preorder_traversal(AVLTreeNode<K, V> * root, List<AVLTreeNode<K, V> *> &nodes) const {
    if (!root) {
        return;
    }
    
    nodes.insert(root);
    preorder_traversal(root->left, nodes);
    preorder_traversal(root->right, nodes);
}

template<class K, class V>
List<AVLTreeNode<K, V> *> AVLTree<K, V>::postorder_traversal() const {
    List<AVLTreeNode<K, V> *> nodes(m_size);

    postorder_traversal(m_root, nodes);

    return nodes;
}
template<class K, class V>
void AVLTree<K, V>::postorder_traversal(AVLTreeNode<K, V> * root, List<AVLTreeNode<K, V> *> &nodes) const {
    if (!root) {
        return;
    }

    postorder_traversal(root->left, nodes);
    postorder_traversal(root->right, nodes);
    nodes.insert(root);
}

template<class K, class V>
AVLTreeNode<K, V> * AVLTree<K, V>::ll_rotation(AVLTreeNode<K, V> * root) {
    AVLTreeNode<K, V> * temp = root->left;
    
    root->left = temp->right;
    temp->right = root;

    return temp;
}
template<class K, class V>
AVLTreeNode<K, V> * AVLTree<K, V>::rr_rotation(AVLTreeNode<K, V> * root) {
    AVLTreeNode<K, V> * temp = root->right;
    
    root->right = temp->left;
    temp->left = root;

    return temp;
}
template<class K, class V>
AVLTreeNode<K, V> * AVLTree<K, V>::rl_rotation(AVLTreeNode<K, V> * root) {
    root->right = ll_rotation(root->right);

    return rr_rotation(root);
}
template<class K, class V>
AVLTreeNode<K, V> * AVLTree<K, V>::lr_rotation(AVLTreeNode<K, V> * root) {
    root->left = rr_rotation(root->left);

    return ll_rotation(root);
}
