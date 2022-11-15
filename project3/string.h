#pragma once

// string.h - String class declaration

#include <iostream>
#include <cstring>

class String {
public:
    String();
    String(char * const &);
    String(const String &);
    ~String();

    String & operator=(const String &);
    String & operator+=(const String &);

    friend std::ostream & operator<<(std::ostream &, const String &);
    friend std::istream & operator>>(std::istream &, String &);

    bool operator==(const String &) const;
    bool operator!=(const String &) const;
    bool operator<(const String &) const;
    bool operator<=(const String &) const;
    bool operator>(const String &) const;
    bool operator>=(const String &) const;

    char operator[](size_t) const;

    // Returns a pointer to a new c-string that is a copy of m_data
    char * get_data() const;

    // Sets m_data to a copy of the c-string passed in
    void set_data(char * const &);

    // Reads a line of input from the user and stores it in m_data
    void get_line(std::istream &, const char = '\n');
    
    // Returns m_size
    size_t length() const;

private:
    char * m_data;
    size_t m_size;
};
