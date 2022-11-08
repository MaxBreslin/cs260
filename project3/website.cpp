#include "website.h"

Website::Website() {
    m_topic = nullptr;
    m_address = nullptr;
    m_summary = nullptr;
    m_review = nullptr;
    m_rating = 0;
}

Website::Website(const Website & obj) {
    m_topic = nullptr;
    m_address = nullptr;
    m_summary = nullptr;
    m_review = nullptr;
    m_rating = obj.m_rating;

    if (obj.m_topic) {
        m_topic = new char[strlen(obj.m_topic) + 1];
        strcpy(m_topic, obj.m_topic);
    }
    if (obj.m_address) {
        m_address = new char[strlen(obj.m_address) + 1];
        strcpy(m_address, obj.m_address);
    }
    if (obj.m_summary) {
        m_summary = new char[strlen(obj.m_summary) + 1];
        strcpy(m_summary, obj.m_summary);
    }
    if (obj.m_review) {
        m_review = new char[strlen(obj.m_review) + 1];
        strcpy(m_review, obj.m_review);
    }
}

Website::Website(char * const & topic, char * const & address, char * const & summary, char * const & review, int rating) {
    m_topic = nullptr;
    m_address = nullptr;
    m_summary = nullptr;
    m_review = nullptr;
    m_rating = rating;

    if (topic) {
        m_topic = new char[strlen(topic) + 1];
        strcpy(m_topic, topic);
    }
    if (address) {
        m_address = new char[strlen(address) + 1];
        strcpy(m_address, address);
    }
    if (summary) {
        m_summary = new char[strlen(summary) + 1];
        strcpy(m_summary, summary);
    }
    if (review) {
        m_review = new char[strlen(review) + 1];
        strcpy(m_review, review);
    }
}

Website::~Website() {
    if (m_topic) {
        delete[] m_topic;
        m_topic = nullptr;
    }
    if (m_address) {
        delete[] m_address;
        m_address = nullptr;
    }
    if (m_summary) {
        delete[] m_summary;
        m_summary = nullptr;
    }
    if (m_review) {
        delete[] m_review;
        m_review = nullptr;
    }
}

Website & Website::operator=(const Website & obj) {
    if (this != &obj) {
        m_rating = obj.m_rating;

        if (m_topic) {
            delete[] m_topic;
            m_topic = nullptr;
        }
        if (obj.m_topic) {
            m_topic = new char[strlen(obj.m_topic) + 1];
            strcpy(m_topic, obj.m_topic);
        }

        if (m_address) {
            delete[] m_address;
            m_address = nullptr;
        }
        if (obj.m_address) {
            m_address = new char[strlen(obj.m_address) + 1];
            strcpy(m_address, obj.m_address);
        }

        if (m_summary) {
            delete[] m_summary;
            m_summary = nullptr;
        }
        if (obj.m_summary) {
            m_summary = new char[strlen(obj.m_summary) + 1];
            strcpy(m_summary, obj.m_summary);
        }

        if (m_review) {
            delete[] m_review;
            m_review = nullptr;
        }
        if (obj.m_review) {
            m_review = new char[strlen(obj.m_review) + 1];
            strcpy(m_review, obj.m_review);
        }
    }
    return *this;
}

void Website::set_topic(char * const & topic) {
    if (m_topic) {
        delete[] m_topic;
        m_topic = nullptr;
    }
    if (topic) {
        m_topic = new char[strlen(topic) + 1];
        strcpy(m_topic, topic);
    }
}

void Website::set_address(char * const & address) {
    if (m_address) {
        delete[] m_address;
        m_address = nullptr;
    }
    if (address) {
        m_address = new char[strlen(address) + 1];
        strcpy(m_address, address);
    }
}

void Website::set_summary(char * const & summary) {
    if (m_summary) {
        delete[] m_summary;
        m_summary = nullptr;
    }
    if (summary) {
        m_summary = new char[strlen(summary) + 1];
        strcpy(m_summary, summary);
    }
}

void Website::set_review(char * const & review) {
    if (m_review) {
        delete[] m_review;
        m_review = nullptr;
    }
    if (review) {
        m_review = new char[strlen(review) + 1];
        strcpy(m_review, review);
    }
}

void Website::set_rating(int rating) {
    m_rating = rating;
}

char * Website::get_topic() const {
    char * temp = nullptr;
    if (m_topic) {
        temp = new char[strlen(m_topic) + 1];
        strcpy(temp, m_topic);
    }
    return temp;
}

char * Website::get_address() const {
    char * temp = nullptr;
    if (m_address) {
        temp = new char[strlen(m_address) + 1];
        strcpy(temp, m_address);
    }
    return temp;
}

char * Website::get_summary() const {
    char * temp = nullptr;
    if (m_summary) {
        temp = new char[strlen(m_summary) + 1];
        strcpy(temp, m_summary);
    }
    return temp;
}

char * Website::get_review() const {
    char * temp = nullptr;
    if (m_review) {
        temp = new char[strlen(m_review) + 1];
        strcpy(temp, m_review);
    }
    return temp;
}

int Website::get_rating() const {
    return m_rating;
}
