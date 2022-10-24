#include "person.h"

Person::Person() {
    m_name = nullptr;
    m_email = nullptr;
    m_special_requirements = nullptr;
    m_receive_coupons = false;
}

Person::Person(const Person &obj) {
    m_name = new char[strlen(obj.m_name) + 1];
    strcpy(m_name, obj.m_name);
    m_email = new char[strlen(obj.m_email) + 1];
    strcpy(m_email, obj.m_email);
    m_special_requirements = new char[strlen(obj.m_special_requirements) + 1];
    strcpy(m_special_requirements, obj.m_special_requirements);
    m_receive_coupons = obj.m_receive_coupons;
}

Person::Person(char * const &name, char * const &email, char * const &special_requirements, const bool receive_coupons) {
    m_name = new char[strlen(name) + 1];
    strcpy(m_name, name);
    m_email = new char[strlen(email) + 1];
    strcpy(m_email, email);
    if (special_requirements) {
        m_special_requirements = new char[strlen(special_requirements) + 1];
        strcpy(m_special_requirements, special_requirements);
    }
    else {
        m_special_requirements = nullptr;
    }
    m_receive_coupons = receive_coupons;
}

Person::~Person() {
    delete[] m_name;
    delete[] m_email;
    delete[] m_special_requirements;
    m_name = nullptr;
    m_email = nullptr;
    m_special_requirements = nullptr;
    m_receive_coupons = false;
}

Person & Person::operator=(const Person &obj) {
    if (this != &obj) {
        delete[] m_name;
        delete[] m_email;
        delete[] m_special_requirements;
        m_name = new char[strlen(obj.m_name) + 1];
        strcpy(m_name, obj.m_name);
        m_email = new char[strlen(obj.m_email) + 1];
        strcpy(m_email, obj.m_email);
        m_special_requirements = new char[strlen(obj.m_special_requirements) + 1];
        strcpy(m_special_requirements, obj.m_special_requirements);
        m_receive_coupons = obj.m_receive_coupons;
    }
    return *this;
}

std::ostream & operator<<(std::ostream &out, const Person &obj) {
    out << "Name: " << obj.m_name << std::endl;
    out << "Email: " << obj.m_email << std::endl;
    out << "Special Requirements: " << obj.m_special_requirements << std::endl;
    out << "Receive Coupons: " << obj.m_receive_coupons << std::endl;
    return out;
}

char * Person::get_name() const {
    char * name = new char[strlen(m_name) + 1];
    strcpy(name, m_name);
    return name;
}

char * Person::get_email() const {
    char * email = new char[strlen(m_email) + 1];
    strcpy(email, m_email);
    return email;
}

char * Person::get_special_requirements() const {
    char * special_requirements = new char[strlen(m_special_requirements) + 1];
    strcpy(special_requirements, m_special_requirements);
    return special_requirements;
}

bool Person::get_coupon_choice() const {
    return m_receive_coupons;
}
