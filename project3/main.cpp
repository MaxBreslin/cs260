#include "main.h"

int main() {
    Table<char *, unsigned int> table(23);

    table.set_hash_function(&hash_string);

    char * topic1 = "computers";
    char * topic2 = "cars";
    char * topic3 = "food";
    char * topic4 = "sports";
    char * topic5 = "music";
    char * topic6 = "movies";
    char * topic7 = "books";
    char * topic8 = "clothing";
    char * topic9 = "toys";
    char * topic10 = "games";
    char * topic11 = "electronics";
    char * topic12 = "furniture";

    table.insert(topic1, 1);
    table.insert(topic2, 2);
    table.insert(topic3, 3);
    table.insert(topic4, 4);
    table.insert(topic5, 5);
    table.insert(topic6, 6);
    table.insert(topic7, 7);
    table.insert(topic8, 8);
    table.insert(topic9, 9);
    table.insert(topic10, 10);
    table.insert(topic11, 11);
    table.insert(topic12, 12);

    std::cout << table << std::endl;
}

unsigned int hash_string(char * const &string) {
    unsigned int hash = 0x811C9DC5;
    size_t length = strlen(string);

    for (size_t i = 0; i < length; i ++) {
        hash *= 0x1000193;
        hash ^= string[i];
    }   

    return hash;
}
