// song.cpp - Song class implementation

#include "song.h"

Song::Song() {
    m_artist = nullptr;
    m_title = nullptr;
    m_length = 0.0;
    m_likes = 0;
}

Song::Song(const char * title, const char * artist, double length, long long likes) {
    m_artist = new char[strlen(artist) + 1];
    strcpy(m_artist, artist);
    m_title = new char[strlen(title) + 1];
    strcpy(m_title, title);
    if (length < 0) {
        m_length = 0.0;
    }
    else {
        m_length = length;
    }
    if (likes < 0) {
        m_likes = 0;
    }
    else {
        m_likes = likes;
    }
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
    m_likes = 0;
}

Song & Song::operator=(const Song &obj) {
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

std::ostream & operator<<(std::ostream &out, const Song &obj) {
    out << obj.m_artist << " - " << obj.m_title << " (" << obj.m_length << " min) [" << obj.m_likes << " likes]";
    return out;
}

char * Song::get_artist() const {
    char * temp = new char[strlen(m_artist) + 1];
    strcpy(temp, m_artist);
    return temp;
}

char * Song::get_title() const {
    char * temp = new char[strlen(m_title) + 1];
    strcpy(temp, m_title);
    return temp;
}

long long Song::get_likes() const {
    return m_likes;
}

double Song::get_length() const {
    return m_length;
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
    if (length < 0) {
        throw "Length cannot be negative";
    }
    m_length = length;
}

void Song::set_likes(long long likes) {
    if (likes < 0) {
        throw "Likes cannot be negative";
    }
    m_likes = likes;
}

bool Song::matches_artist_and_title(const Song &rhs) const {
    return strcmp(m_artist, rhs.m_artist) == 0 && strcmp(m_title, rhs.m_title) == 0;
}

bool Song::operator==(const Song &rhs) const {
    return m_likes == rhs.m_likes;
}
bool Song::operator>(const Song &rhs) const {
    return m_likes > rhs.m_likes;
}
bool Song::operator>=(const Song &rhs) const {
    return *this > rhs || *this == rhs;
}
bool Song::operator<(const Song &rhs) const {
    return !(*this >= rhs);
}
bool Song::operator<=(const Song &rhs) const {
    return !(*this > rhs);
}
bool Song::operator!=(const Song &rhs) const {
    return !(*this == rhs);
}
