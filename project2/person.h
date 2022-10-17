#pragma once

#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>

class Person {
public:
    Person();
    Person(const Person &);
    Person(const char * &, const char * &, const char * &, const bool &);
    ~Person();

    Person & operator=(const Person &);
    friend std::ostream & operator<<(std::ostream &, const Person &);
    
private:
    char * m_name;
    char * m_email;
    char * m_special_requirements;
    bool m_receive_coupons;
};