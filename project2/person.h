#pragma once

#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>

class Person {
public:
    Person();
    Person(const Person &);
    Person(char * const &, char * const &, char * const &, const bool);
    ~Person();

    Person & operator=(const Person &);
    friend std::ostream & operator<<(std::ostream &, const Person &);

    char * get_name() const;
    char * get_email() const;
    char * get_special_requirements() const;
    bool get_coupon_choice() const;
    
private:
    char * m_name;
    char * m_email;
    char * m_special_requirements;
    bool m_receive_coupons;
};
