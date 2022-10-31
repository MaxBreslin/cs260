// main.h - main function and menu functions

#pragma once

#include "queue.h"
#include "stack.h"
#include "person.h"

int main();

// Opens the passed file and reads the contents into
// the passed Queue and Stack.
void load_people(Queue<Person> &, Stack<Person> &, std::ifstream &);

// Displays a welcome message
void welcome();

// Displays a menu, prompts the user to choose an option,
// and returns the user's choice
int menu();

// Reads characters from the passed stream until the delimiter
// character is reached, and returns a pointer to the dynamically
// allocated array of the characters read.
char * get_name(std::istream &, const char);

// Prompts the user to enter a choice of coupon (y/n)
// and continues to ask until the user enters a valid choice.
bool get_coupon_choice(std::istream &);

// Prompts the user to enter a name, email, special requirements,
// and coupon choice, and adds the person to the passed Queue.
// If the person wants coupons, the person is also added to the
// passed Stack.
void push_person(Queue<Person> &, Stack<Person> &);

// Removes the first person from the passed Queue and displays
// the person's name.
void pop_from_line(Queue<Person> &);

// Removes the first person from the passed Stack and displays
// the person's name.
void pop_from_stack(Stack<Person> &, std::ofstream &);

// Displays the contents of the passed Queue.
void display_line(const Queue<Person> &);

// Displays the contents of the passed Stack.
void display_stack(const Stack<Person> &);
