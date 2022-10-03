#pragma once

#include "node.h"

class SongList {
public:
    SongList();
    SongList(const SongList &);
    ~SongList();

    SongList & operator=(const SongList &);
    friend std::ostream & operator<<(std::ostream &, const SongList &);

    // Calls the recursive form of add with the passed Song and m_head
    void add(const Song &);

    // Removes the first song with a matching artist and title
    Song remove(const Song &);

    // Removes all songs with fewer than the passed number of likes
    void remove_with_fewer_likes(long long);

    // Displays all songs by the passed artist
    void display_artist(const char * &) const;

private:
    Node * m_head;
    size_t m_size;

    // Recursively traverses the list and adds the passed song in the correct
    // position (sorted by number of likes, descending)
    Node * add(const Song &, Node * &);
};
