#include "website.h"

Website::Website() {
    m_rating = 0;
}

Website::Website(const Website &obj) {
    m_rating = obj.m_rating;
    m_topic = obj.m_topic;
    m_address = obj.m_address;
    m_summary = obj.m_summary;
    m_review = obj.m_review;
}

Website::Website(const String &topic, const String &address, const String &summary, const String &review, int rating) {
    m_topic = topic;
    m_address = address;
    m_summary = summary;
    m_review = review;
    m_rating = rating;
}

Website::~Website() {
    m_topic.~String();
    m_address.~String();
    m_summary.~String();
    m_review.~String();
}

Website & Website::operator=(const Website &obj) {
    if (this != &obj) {
        m_rating = obj.m_rating;
        m_topic = obj.m_topic;
        m_address = obj.m_address;
        m_summary = obj.m_summary;
        m_review = obj.m_review;
    }
    return *this;
}

std::ostream & operator<<(std::ostream &out, const Website &obj) {
    out << obj.m_topic << ", ";
    out <<  obj.m_address << ", ";
    out <<  obj.m_summary << ", ";
    out << obj.m_review << ", ";
    out << obj.m_rating;
    return out;
}

void Website::set_topic(const String &topic) {
    m_topic = topic;
}

void Website::set_address(const String &address) {
    m_address = address;
}

void Website::set_summary(const String &summary) {
    m_summary = summary;
}

void Website::set_review(const String &review) {
    m_review = review;
}

void Website::set_rating(int rating) {
    m_rating = rating;
}

String Website::get_topic() const {
    return m_topic;
}

String Website::get_address() const {
    return m_address;
}

String Website::get_summary() const {
    return m_summary;
}

String Website::get_review() const {
    return m_review;
}

int Website::get_rating() const {
    return m_rating;
}

bool Website::operator==(const Website &obj) const {
    if (m_topic == obj.m_topic && m_address == obj.m_address && m_summary == obj.m_summary && m_review == obj.m_review && m_rating == obj.m_rating) {
        return true;
    }
    return false;
}
