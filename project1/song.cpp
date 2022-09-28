#include "song.h"

Song::Song() {
    m_artist = nullptr;
    m_title = nullptr;
    m_length = 0.0;
    m_likes = 0U;
}

Song::Song(const char * title, const char * artist, double length, unsigned int likes) {
    m_artist = new char[strlen(artist) + 1];
    strcpy(m_artist, artist);
    m_title = new char[strlen(title) + 1];
    strcpy(m_title, title);
    m_length = length;
    m_likes = likes;
}

Song::Song(const Song & obj) {
    m_artist = new char[strlen(obj.m_artist) + 1];
    strcpy(m_artist, obj.m_artist);
    m_title = new char[strlen(obj.m_title) + 1];
    strcpy(m_title, obj.m_title);
    m_length = obj.m_length;
    m_likes = obj.m_likes;
}

Song::~Song() {
    delete[] m_artist;
    delete[] m_title;
    m_artist = nullptr;
    m_title = nullptr;
    m_length = 0.0;
    m_likes = 0U;
}

Song & Song::operator=(const Song & obj) {
    if (this != &obj) {
        delete[] m_artist;
        delete[] m_title;
        m_artist = new char[strlen(obj.m_artist) + 1];
        strcpy(m_artist, obj.m_artist);
        m_title = new char[strlen(obj.m_title) + 1];
        strcpy(m_title, obj.m_title);
        m_length = obj.m_length;
        m_likes = obj.m_likes;
    }
    return *this;
}

std::ostream & operator<<(std::ostream & out, const Song & obj) {
    out << obj.m_artist << " - " << obj.m_title << " (" << obj.m_length << " min) [" << obj.m_likes << " likes]";
    return out;
}

char * Song::get_artist() const {
    char * temp = new char[strlen(m_artist) + 1];
    strcpy(temp, m_artist);
    return temp;
}

unsigned int Song::get_likes() const {
    return m_likes;
}

void Song::set_artist(const char * artist) {
    delete[] m_artist;
    m_artist = new char[strlen(artist) + 1];
    strcpy(m_artist, artist);
}

void Song::set_title(const char * title) {
    delete[] m_title;
    m_title = new char[strlen(title) + 1];
    strcpy(m_title, title);
}

void Song::set_length(double length) {
    m_length = length;
}

void Song::set_likes(unsigned int likes) {
    m_likes = likes;
}

bool Song::operator==(const Song & rhs) const {
    return (strcmp(m_artist, rhs.m_artist) == 0 && strcmp(m_title, rhs.m_title) == 0);
}
bool Song::operator>(const Song & rhs) const {
    return m_likes > rhs.m_likes;
}
bool Song::operator>=(const Song & rhs) const {
    return *this > rhs || *this == rhs;
}
bool Song::operator<(const Song & rhs) const {
    return !(*this >= rhs);
}
bool Song::operator<=(const Song & rhs) const {
    return !(*this > rhs);
}
bool Song::operator!=(const Song & rhs) const {
    return !(*this == rhs);
}
