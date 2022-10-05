// songlist.h - SongList class declaration

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
    // Parameters:
    //      song - The song to add to the list
    void add(const Song &);

    // Removes the first song with a matching artist and title
    // Parameters:
    //      song - The song to remove from the list
    Song remove(const Song &);

    // Removes all songs with fewer than the passed number of likes
    // Parameters:
    //      likes - The minimum number of likes
    void remove_with_fewer_likes(long long);

    // Displays all songs by the passed artist
    // Parameters:
    //      artist - The artist to display
    void display_artist(const char * &) const;

private:
    Node * m_head;
    size_t m_size;

    // Recursively traverses the list and adds the passed song in the correct
    // position (sorted by number of likes, descending)
    // Parameters:
    //      song - The song to add to the list
    //      curr - The current node in the list
    Node * add(const Song &, Node * &);
};
