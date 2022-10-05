// songlist.cpp - SongList class implementation

#include "songlist.h"

SongList::SongList() {
    m_head = nullptr;
    m_size = 0;
}

SongList::SongList(const SongList &obj) {
    m_head = nullptr;
    m_size = 0;
    Node * temp = obj.m_head;

    while (temp) {
        add(*temp->data);
        m_size ++;

        temp = temp->next;
    }
}

SongList::~SongList() {
    Node * temp = m_head;

    while (temp) {
        Node * next = temp->next;
        delete temp;
        temp = next;
    }

    m_head = nullptr;
    m_size = 0;
}

SongList & SongList::operator=(const SongList &obj) {
    if (this != &obj) {
        Node * temp = m_head;

        while (temp) {
            Node * next = temp->next;
            delete temp;
            temp = next;
        }

        m_head = nullptr;
        m_size = 0;
        temp = obj.m_head;

        while (temp) {
            add(*temp->data);
            m_size ++;

            temp = temp->next;
        }
    }

    return *this;
}

std::ostream & operator<<(std::ostream &out, const SongList &obj) {
    Node * temp = obj.m_head;

    while (temp) {
        out << *temp->data << std::endl;
        temp = temp->next;
    }

    return out;
}

void SongList::add(const Song &obj) {
    add(obj, m_head);
}
Node * SongList::add(const Song &obj, Node * &curr) {
    if (!curr) {
        curr = new Node(obj);
    }
    else if (obj > *curr->data) {
        Node * temp = curr;
        curr = new Node(obj);
        curr->next = temp;
    }
    else {
        curr->next = add(obj, curr->next);
    }

    return curr;
}

Song SongList::remove(const Song &obj) {
    Node * curr = m_head;
    Node * prev = nullptr;
    Node * temp = nullptr;
    Song deleted_song;

    while (curr) {
        if (curr->data->matches_artist_and_title(obj)) {
            break;
        }
        prev = curr;
        curr = curr->next;
    }

    if (!curr) {
        throw "Song not found";
    }

    deleted_song = *curr->data;

    if (prev) {
        temp = curr;
        prev->next = curr->next;
    }
    else {
        temp = m_head;
        m_head = m_head->next;
    }

    delete temp;
    m_size --;

    return deleted_song;
}

void SongList::remove_with_fewer_likes(long long likes) {
    Node * curr = m_head;
    Node * prev = nullptr;

    while (curr) {
        if (curr->data->get_likes() < likes) {
            if (prev) {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
            else {
                m_head = curr->next;
                delete curr;
                curr = m_head;
            }
            m_size --;
        }
        else {
            prev = curr;
            curr = curr->next;
        }
    }
}

void SongList::display_artist(const char * &artist) const {
    Node * curr = m_head;
    char * temp = nullptr;

    while (curr) {
        temp = curr->data->get_artist();
        if (strcmp(temp, artist) == 0) {
            std::cout << *curr->data << std::endl;
        }
        delete[] temp;
        curr = curr->next;
    }
}
