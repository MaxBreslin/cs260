#pragma once

#include "string.h"
#include <cstring>
#include <iostream>

class Website {
public:
    Website();
    Website(const Website &);
    Website(const String &, const String &, const String &, const String &, int);
    ~Website();

    Website & operator=(const Website &);

    friend std::ostream & operator<<(std::ostream &, const Website &);

    void set_topic(const String &);
    void set_address(const String &);
    void set_summary(const String &);
    void set_review(const String &);
    void set_rating(int);

    String get_topic() const;
    String get_address() const;
    String get_summary() const;
    String get_review() const;
    int get_rating() const;

    bool operator==(const Website &) const;

private:
    String m_topic;
    String m_address;
    String m_summary;
    String m_review;
    int m_rating;
};
