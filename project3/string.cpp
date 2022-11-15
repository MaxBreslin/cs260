// string.cpp - String class implementation

#include "string.h"

String::String() {
    m_data = nullptr;
    m_size = 0;
}

String::String(char * const &data) {
    m_data = nullptr;
    m_size = 0;

    if (data) {
        m_data = new char[strlen(data) + 1];
        strcpy(m_data, data);
        m_size = strlen(data);
    }
}

String::String(const String &obj) {
    m_data = nullptr;
    m_size = obj.m_size;

    if (obj.m_data) {
        m_data = new char[strlen(obj.m_data) + 1];
        strcpy(m_data, obj.m_data);
    }
}

String::~String() {
    delete[] m_data;
    m_data = nullptr;
    m_size = 0;
}

String & String::operator=(const String &obj) {
    if (this != &obj) {
        delete[] m_data;
        m_data = nullptr;
        m_size = obj.m_size;

        if (obj.m_data) {
            m_data = new char[obj.m_size + 1];
            strcpy(m_data, obj.m_data);
        }
    }
    return *this;
}

String & String::operator+=(const String &obj) {
    if (obj.m_data) {
        char * temp = new char[m_size + obj.m_size + 1];
        strcpy(temp, m_data);
        strcat(temp, obj.m_data);
        delete[] m_data;
        m_data = temp;
        m_size += obj.m_size;
    }
    return *this;
}

std::ostream & operator<<(std::ostream &out, const String &obj) {
    out << obj.m_data;
    return out;
}
std::istream & operator>>(std::istream &in, String &obj) {
    obj.get_line(in);
    return in;
}

bool String::operator==(const String &obj) const {
    if (!(m_data && obj.m_data)) {
        return false;
    }
    return strcmp(m_data, obj.m_data) == 0;
}
bool String::operator!=(const String &obj) const {
    return !(*this == obj);
}
bool String::operator<(const String &obj) const {
    if (!(m_data && obj.m_data)) {
        return false;
    }
    return strcmp(m_data, obj.m_data) < 0;
}
bool String::operator<=(const String &obj) const {
    return (*this < obj) || (*this == obj);
}
bool String::operator>(const String &obj) const {
    return !(*this <= obj);
}
bool String::operator>=(const String &obj) const {
    return !(*this < obj);
}

char String::operator[](size_t index) const {
    if (index >= m_size) {
        throw "Index out of range";
    }
    if (!m_data) {
        throw "String is empty";
    }

    return m_data[index];
}

char * String::get_data() const {
    if (!m_data) {
        return nullptr;
    }

    char * temp = new char[m_size + 1];
    strcpy(temp, m_data);
    return temp;
}
void String::set_data(char * const &data) {
    delete[] m_data;
    m_data = nullptr;
    m_size = 0;
    
    if (data) {
        m_data = new char[strlen(data) + 1];
        strcpy(m_data, data);
        m_size = strlen(data);
    }
}


void String::get_line(std::istream &in, const char delim) {
    char * data = nullptr;
    char * temp = nullptr;
    int size = 0;
    char byte = 0;

    delete[] m_data;

    while (in.good() && in.peek() != delim) {
        byte = in.get();
        if (data) {
            temp = new char[size + 2];
            memset(temp, 0, size + 2);
            strcpy(temp, data);
            delete[] data;
            data = temp;
            data[size ++] = byte;
        } 
        else {
            data = new char[size + 2];
            memset(data, 0, size + 2);
            data[0] = byte;
            size = 1;
        }
    }
    in.ignore(2, delim);
    in.clear();

    m_data = data;
    m_size = size;
}

size_t String::length() const {
    return m_size;
}
