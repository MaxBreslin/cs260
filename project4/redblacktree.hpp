#pragma once

#include "redblacktreenode.hpp"

template<class K, class V>
class RedBlackTree {
public:
    RedBlackTree();
    RedBlackTree(const RedBlackTree<K, V> &);
    ~RedBlackTree();

    RedBlackTree & operator=(const RedBlackTree<K, V> &);

    template<class kK, class vV>
    friend std::ostream & operator<<(std::ostream &, const RedBlackTree<kK, vV> &);

    size_t height() const;
    
    size_t max_width() const;

    void insert(const K &, const V &);

    // List<V> remove(const K &);

    // List<V> retrieve(const K &) const;

    // void edit(const K &, const V &, const V &);

    void display() const;

private:
    size_t height(RedBlackTreeNode<K, V> *) const;

    size_t width(RedBlackTreeNode<K, V> *, unsigned int) const;

    List<RedBlackTreeNode<K, V> *> level(unsigned int) const;
    void level(unsigned int, RedBlackTreeNode<K, V> *, List<RedBlackTreeNode<K, V> *> &) const;

    RedBlackTreeNode<K, V> * insert(const K &, const V &, RedBlackTreeNode<K, V> *);

    List<RedBlackTreeNode<K, V> *> inorder_traversal() const;
    void inorder_traversal(RedBlackTreeNode<K, V> *, List<RedBlackTreeNode<K, V> *> &) const;

    List<RedBlackTreeNode<K, V> *> preorder_traversal() const;
    void preorder_traversal(RedBlackTreeNode<K, V> *, List<RedBlackTreeNode<K, V> *> &) const;

    List<RedBlackTreeNode<K, V> *> postorder_traversal() const;
    void postorder_traversal(RedBlackTreeNode<K, V> *, List<RedBlackTreeNode<K, V> *> &) const;

    RedBlackTreeNode<K, V> * m_root;
    size_t m_size;
};

template<class K, class V>
RedBlackTree<K, V>::RedBlackTree() {
    m_root = nullptr;
    m_size = 0;
}

template<class K, class V>
RedBlackTree<K, V>::RedBlackTree(const RedBlackTree<K, V> &obj) {
    List<RedBlackTreeNode<K, V> *> nodes = obj.preorder_traversal();
    m_size = obj.m_size;

    for (size_t i = 0; i < m_size; i ++) {
        insert(nodes[i]);
    }
}

template<class K, class V>
RedBlackTree<K, V>::~RedBlackTree() {
    List<RedBlackTreeNode<K, V> *> nodes = postorder_traversal();

    for (size_t i = 0; i < m_size; i ++) {
        delete nodes[i];
    }

    m_root = nullptr;
    m_size = 0;
}

template<class K, class V>
RedBlackTree<K, V> & RedBlackTree<K, V>::operator=(const RedBlackTree<K, V> &obj) {
    if (this != &obj) {
        List<RedBlackTreeNode<K, V> *> nodes = postorder_traversal();

        for (size_t i = 0; i < m_size; i ++) {
            delete nodes[i];
        }

        m_root = nullptr;
        m_size = 0;

        List<RedBlackTreeNode<K, V> *> new_nodes = obj.preoder_traversal();
        for (size_t i = 0; i < obj.m_size; i ++) {
            insert(*new_nodes[i]->key, *new_nodes[i]->value);
        }
    }
    return *this;
}

template<class K, class V>
std::ostream & operator<<(std::ostream &out, const RedBlackTree<K, V> &obj) {
    List<RedBlackTreeNode<K, V> *> nodes = obj.inorder_traversal();

    for (size_t i = 0; i < obj.m_size; i ++) {
        out << *nodes[i] << std::endl;
    }

    return out;
}

template<class K, class V>
size_t RedBlackTree<K, V>::height() const {
    return height(m_root);
}

template<class K, class V>
size_t RedBlackTree<K, V>::height(RedBlackTreeNode<K, V> * root) const {
    if (!root) {
        return 0;
    }

    size_t left_height = height(root->left);
    size_t right_height = height(root->right);
    return left_height > right_height ? left_height + 1 : right_height + 1;
}

template<class K, class V>
size_t RedBlackTree<K, V>::max_width() const {
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
size_t RedBlackTree<K, V>::width(RedBlackTreeNode<K, V> * root, unsigned int l) const {
    if (!root) {
        return 0;
    }

    if (l == 0) {
        return 1;
    }

    return width(root->left, l - 1) + width(root->right, l - 1);
}

template<class K, class V>
List<RedBlackTreeNode<K, V> *> RedBlackTree<K, V>::level(unsigned int l) const {
    List<RedBlackTreeNode<K, V> *> nodes(width(m_root, l));
    
    level(l, m_root, nodes);

    return nodes;
}

template<class K, class V>
void RedBlackTree<K, V>::level(unsigned int l, RedBlackTreeNode<K, V> * root, List<RedBlackTreeNode<K, V> *> &nodes) const {
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
void RedBlackTree<K, V>::insert(const K &key, const V &value) {
    m_root = insert(key, value, m_root);
}
template<class K, class V>
RedBlackTreeNode<K, V> * RedBlackTree<K, V>::insert(const K &key, const V &value, RedBlackTreeNode<K, V> * root) {
    if (!root) {
        m_size ++;
        return new RedBlackTreeNode<K, V>(key, value);
    }
    if (key < *root->key) {
        root->left = insert(key, value, root->left);
    }
    else {
        root->right = insert(key, value, root->right);
    }
    return root;
}

template<class K, class V>
void RedBlackTree<K, V>::display() const {
    size_t h = height();

    List<List<RedBlackTreeNode<K, V> *>> levels;

    for (size_t i = 0; i < h; i ++) {
        levels.insert(level(i));
    }
    

    unsigned int pre_space = 0;
    unsigned int between_space = 0;
    unsigned int nodes_in_full_layer = 0; 

    for (size_t i = 0; i < h; i ++) {
        pre_space = pow(2, h - 1 - i) - 1;
        nodes_in_full_layer = pow(2, i);
        between_space = (pow(2, h) - 1 - 2 * pre_space - nodes_in_full_layer) / (nodes_in_full_layer - 1);

        if (between_space) {
            // for (unsigned int j = 0; j < pre_space; j ++) {
            //     std::cout << " ";
            // }

            // for (unsigned int j = 0; j < nodes_in_full_layer; j ++) {
            //     if (j % 2 == 1) {
            //         for (unsigned int k = 0; k < between_space; k ++) {
            //             std::cout << " ";
            //         }
            //         continue;
            //     }
            //     if (levels[i][j] && levels[i][j + 1]) {
            //         std::cout << "+";
            //         for (unsigned int k = 0; k < between_space; k ++) {
            //             std::cout << "-";
            //         }
            //         std::cout << "+";
            //     }
            //     else if (levels[i][j]) {
            //         std::cout << "+";
            //         for (unsigned int k = 0; k < between_space; k ++) {
            //             std::cout << "-";
            //         }
            //         std::cout << " ";
            //     }
            //     else if (levels[i][j + 1]) {
            //         std::cout << " ";
            //         for (unsigned int k = 0; k < between_space; k ++) {
            //             std::cout << "-";
            //         }
            //         std::cout << "+";
            //     }
            //     else {
            //         for (unsigned int k = 0; k < between_space + 2; k ++) {
            //             std::cout << " ";
            //         }
            //     }
            // }
            // std::cout << std::endl;

            
        }

        for (unsigned int j = 0; j < pre_space; j ++) {
            std::cout << " ";
        }

        for (unsigned int j = 0; j < nodes_in_full_layer; j ++) {
            if (levels[i][j]) {
                std::cout << *levels[i][j]->value;
            }
            else {
                std::cout << " ";
            }

            for (unsigned int k = 0; k < between_space; k ++) {
                std::cout << " ";
            }
        }

        std::cout << std::endl;
    }
}

template<class K, class V>
List<RedBlackTreeNode<K, V> *> RedBlackTree<K, V>::inorder_traversal() const {
    List<RedBlackTreeNode<K, V> *> nodes(m_size);

    inorder_traversal(m_root, nodes);

    return nodes;
}
template<class K, class V>
void RedBlackTree<K, V>::inorder_traversal(RedBlackTreeNode<K, V> * root, List<RedBlackTreeNode<K, V> *> &nodes) const {
    if (!root) {
        return;
    }
    
    inorder_traversal(root->left, nodes);
    nodes.insert(root);
    inorder_traversal(root->right, nodes);
}

template<class K, class V>
List<RedBlackTreeNode<K, V> *> RedBlackTree<K, V>::preorder_traversal() const {
    List<RedBlackTreeNode<K, V> *> nodes(m_size);

    preorder_traversal(m_root, nodes);

    return nodes;
}
template<class K, class V>
void RedBlackTree<K, V>::preorder_traversal(RedBlackTreeNode<K, V> * root, List<RedBlackTreeNode<K, V> *> &nodes) const {
    if (!root) {
        return;
    }
    
    nodes.insert(root);
    preorder_traversal(root->left, nodes);
    preorder_traversal(root->right, nodes);
}

template<class K, class V>
List<RedBlackTreeNode<K, V> *> RedBlackTree<K, V>::postorder_traversal() const {
    List<RedBlackTreeNode<K, V> *> nodes(m_size);

    postorder_traversal(m_root, nodes);

    return nodes;
}
template<class K, class V>
void RedBlackTree<K, V>::postorder_traversal(RedBlackTreeNode<K, V> * root, List<RedBlackTreeNode<K, V> *> &nodes) const {
    if (!root) {
        return;
    }

    postorder_traversal(root->left, nodes);
    postorder_traversal(root->right, nodes);
    nodes.insert(root);
}
