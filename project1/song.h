#pragma once

#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>

class Song {
public:
    Song();
    Song(const char *, const char *, double, unsigned int);
    Song(const Song &);
    ~Song();

    Song & operator=(const Song &);
    friend std::ostream & operator<<(std::ostream &, const Song &);

    char * get_artist() const;
    unsigned int get_likes() const;

    void set_artist(const char *);
    void set_title(const char *);
    void set_length(double);
    void set_likes(unsigned int);

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
    unsigned int m_likes;
};
