/*
    Max Breslin - October 24st, 2022
    CS260 Data Structures
    Project 2

*/

// main.cpp - main function and menu functions

#include "main.h"

int main() {
    Queue<Person> line;
    Stack<Person> people;

    std::ofstream promo_file;
    promo_file.open("promos.txt");
    if (!promo_file) {
        std::cout << "Error opening file" << std::endl;
        return EXIT_FAILURE;
    }

    int option = 0;

    std::cout.setf(std::ios::fixed, std::ios::floatfield);
    std::cout.precision(2);

    welcome();

    while ((option = menu()) != 1) {
        switch(option) {
            case 2:
                push_person(line, people);
                break;
            case 3:
                pop_from_line(line);
                break;
            case 4:
                pop_from_stack(people, promo_file);
                break;
            case 5:
                display_line(line);
                break;
            case 6:
                display_stack(people);
                break;
            default:
                std::cout << "Invalid option" << std::endl;
                return EXIT_FAILURE;
        }
     }

    std::cout << "[done]" << std::endl;

    return EXIT_SUCCESS;
}

void welcome() {
    std::cout << "Welcome to Waiting Line Manager! All input is case sensitive." << std::endl << std::endl;
}

int menu() {
    int option = 0;

    std::cout << std::endl
              << "Please enter one of the following options:" << std::endl
              << "1 - Quit the program" << std::endl
              << "2 - Add a new person to the line" << std::endl
              << "3 - Seat the next person in line" << std::endl
              << "4 - Send a promotional offer to the top customer" << std::endl
              << "5 - Display waiting line" << std::endl
              << "6 - Display promotional stack" << std::endl
              << "Enter option: ";

    std::cin >> option;
    while (std::cin.fail() || option < 1 || option > 6) {
        std::cin.clear();
        std::cin.ignore(1024, '\n');
        std::cout << "Invalid option" << std::endl;
        std::cout << "Enter option: ";
        std::cin >> option;
    }
    std::cin.ignore(2, '\n');

    std::cout << std::endl;

    return option;
}

char * get_name(std::istream &in, const char delim = '\n') {
    char * name = nullptr;
    char * temp = nullptr;
    int size = 0;
    char byte = 0;

    while (in.good() && in.peek() != delim) {
        byte = in.get();
        if (name) {
            temp = new char[size + 2];
            memset(temp, 0, size + 2);
            strcpy(temp, name);
            memset(name, 0, size + 1);
            delete[] name;
            name = temp;
            name[size ++] = byte;
        } 
        else {
            name = new char[size + 2];
            memset(name, 0, size + 2);
            name[0] = byte;
            size = 1;
        }
    }
    in.ignore(2, delim);
    in.clear();

    return name;
}


bool get_coupon_choice(std::istream &in) {
    char choice = 0;

    in >> choice;
    while (in.fail() || (choice != 'y' && choice != 'n')) {
        in.clear();
        in.ignore(1024, '\n');
        std::cout << "Invalid option" << std::endl;
        std::cout << "Receive coupons? (y/n): ";
        in >> choice;
    }
    in.ignore(2, '\n');

    return choice == 'y';
}

void push_person(Queue<Person> &line, Stack<Person> &people) {
    char * name = nullptr;
    char * email = nullptr;
    char * special_requirements = nullptr;
    bool receive_coupons = false;

    std::cout << "Enter name (e.g. John Doe): ";
    name = get_name(std::cin);
    std::cout << "Enter email (e.g. JohnDoe@gmail.com): ";
    email = get_name(std::cin);
    std::cout << "Enter special requirements (e.g. High chair needed)\n"
              << "Leave blank for no requirements: ";
    special_requirements = get_name(std::cin);
    std::cout << "Receive coupons? (y/n): ";
    receive_coupons = get_coupon_choice(std::cin);

    Person person(name, email, special_requirements, receive_coupons);

    line.push(person);
    std::cout << "\"" << name << "\"" << " added to waiting line" << std::endl;

    if (receive_coupons) {
        people.push(person);
        std::cout << "\"" << name << "\"" << " added to promotional stack" << std::endl;
    }

    delete[] name;
    delete[] email;
    delete[] special_requirements;
}

void pop_from_line(Queue<Person> &line) {
    if (line.is_empty()) {
        std::cout << "No one in line" << std::endl;
        return;
    }

    Person person = line.pop();
    char * name = person.get_name();
    std::cout << "Seating \"" << name << "\"" << std::endl;
    delete[] name;
}

void pop_from_stack(Stack<Person> &people, std::ofstream &promo_file) {
    if (people.is_empty()) {
        std::cout << "No one in stack" << std::endl;
        return;
    }

    Person person = people.pop();
    char * name = person.get_name();
    std::cout << "Sending promotional offer to \"" << name << "\"" << std::endl;
    promo_file << person << std::endl;
    delete[] name;
}

void display_line(const Queue<Person> &line) {
    if (line.is_empty()) {
        std::cout << "No one in line" << std::endl;
        return;
    }

    std::cout << "Waiting line:" << std::endl;
    line.display();
}

void display_stack(const Stack<Person> &people) {
    if (people.is_empty()) {
        std::cout << "No one in stack" << std::endl;
        return;
    }

    std::cout << "Promotional stack:" << std::endl;
    people.display();
}
