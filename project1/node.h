#pragma once

#include "song.h"

struct Node {
    Node();
    Node(const Song &);
    ~Node();

    Song * data;
    Node * next;
};
