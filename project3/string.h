#pragma once

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

    char * get_data() const;
    void set_data(char * const &);

    void getline(std::istream &, const char = '\n');
    
    size_t length() const;

private:
    char * m_data;
    size_t m_size;
};
