#include "main.h"




int main() {
    Table<char *, unsigned int> table(23);

    table.set_hash_function(&hash_string);

    char * name = "John Doe";
    char * dog = "Husky";

    unsigned int sum = sum_ascii(name);
    
    table.insert(name, sum);
    table.insert(dog, sum_ascii(dog));
    table.insert(name, sum);

    table.remove(name);
    table.display();

    table.~Table();
}

unsigned int sum_ascii(char * const &string) {
    unsigned int sum = 0; 

    for (size_t i = 0; i < strlen(string); i ++) {
        sum += string[i];
    }

    return sum;
}

unsigned int hash_string(char * const &string) {
    unsigned int result = 0;

    for (size_t i = 0; i < strlen(string); i ++) {
        result += power(string[i], i);
    }

    return result;
}

unsigned int power(unsigned int x, unsigned int p) {
    unsigned int result = 1;
    
    while (p) {
        result *= x;
        p --;
    }

    return result;
}
