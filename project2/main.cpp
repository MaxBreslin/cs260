#include "main.h"

int main() {
    Stack<Person> stack;

    std::cout << stack << std::endl;

    const char * name = "Ivan";
    const char * email = "ivan@gmail.com";
    const char * special_requirements = "";
    const bool receive_coupons = true;
    stack.push(Person(name, email, special_requirements, receive_coupons));
    stack.push(Person(name, email, special_requirements, receive_coupons));
    stack.push(Person(name, email, special_requirements, receive_coupons));
    stack.push(Person(name, email, special_requirements, receive_coupons));

    std::cout << stack << std::endl;
    stack.push(Person(name, email, special_requirements, receive_coupons));
    stack.push(Person(name, email, special_requirements, receive_coupons));
    stack.push(Person(name, email, special_requirements, receive_coupons));
    std::cout << stack << std::endl;

    

    return EXIT_SUCCESS;
}
