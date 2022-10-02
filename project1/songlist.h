#pragma once

#include "node.h"

class SongList {
public:
    SongList();
    SongList(const SongList &);
    ~SongList();

    SongList & operator=(const SongList &);
    friend std::ostream & operator<<(std::ostream &, const SongList &);

    void add(const Song &);
    Song remove(const Song &);
    void remove_with_fewer_likes(long long);
    void display_artist(const char * &) const;

private:
    Node * m_head;
    size_t m_size;

    Node * add(const Song &, Node * &);
};
