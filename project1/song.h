// song.h - Song class declaration

#pragma once

#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>

class Song {
public:
    Song();
    Song(const char *, const char *, double, long long);
    Song(const Song &);
    ~Song();

    Song & operator=(const Song &);
    friend std::ostream & operator<<(std::ostream &, const Song &);

    // Returns a pointer to a dynamically allocated char array containing 
    // the member variable
    char * get_artist() const;
    char * get_title() const;

    // Returns the member variable
    double get_length() const;
    long long get_likes() const;

    // Sets m_artist
    // Parameters:
    //      artist - The artist to set
    void set_artist(const char *);
    // Sets m_title
    // Parameters:
    //      title - The title to set
    void set_title(const char *);
    // Sets m_length
    // Parameters:
    //      length - The length to set
    void set_length(double);
    // Sets m_likes
    // Parameters:
    //      likes - The likes to set
    void set_likes(long long);

    // Returns true if the two songs have the same artist and title
    // Parameters:
    //      song - The song to compare to
    bool matches_artist_and_title(const Song &) const;

    // Comparisons based on m_likes
    bool operator==(const Song &) const;
    bool operator!=(const Song &) const;
    bool operator>(const Song &) const;
    bool operator<(const Song &) const;
    bool operator>=(const Song &) const;
    bool operator<=(const Song &) const;

private:
    char * m_artist;
    char * m_title;
    double m_length;
    long long m_likes;
};
