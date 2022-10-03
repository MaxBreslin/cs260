#include "node.h"

Node::Node() {
    data = nullptr;
    next = nullptr;
}

Node::Node(const Song &obj) {
    data = new Song(obj);
    next = nullptr;
}

Node::~Node() {
    delete data;
    data = nullptr;
    next = nullptr;
}
