#pragma once

#include <cstring>

class Website {
public:
    Website();
    Website(const Website &);
    Website(char * const &, char * const &, char * const &, char * const &, int);
    ~Website();

    Website & operator=(const Website &);

    void set_topic(char * const &);
    void set_address(char * const &);
    void set_summary(char * const &);
    void set_review(char * const &);
    void set_rating(int);

    char * get_topic() const;
    char * get_address() const;
    char * get_summary() const;
    char * get_review() const;
    int get_rating() const;

private:
    char * m_topic;
    char * m_address;
    char * m_summary;
    char * m_review;
    int m_rating;
};
