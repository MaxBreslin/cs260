// main.h - main function and menu functions

#pragma once

#include "queue.h"
#include "stack.h"
#include "person.h"

int main();

// Displays a welcome message
void welcome();

// Displays a menu, prompts the user to choose an option,
// and returns the user's choice
int menu();

// Reads characters from the passed stream until the delimiter
// character is reached, and returns a dynamically allocated
// array of the characters read
// Parameters:
//     stream - the stream to read from
//     delimiter - the character to stop reading at
char * get_name(std::istream &, const char);

bool get_coupon_choice(std::istream &);


void push_person(Queue<Person> &, Stack<Person> &);

void pop_from_line(Queue<Person> &);

void pop_from_stack(Stack<Person> &);

void display_line(const Queue<Person> &);

void display_stack(const Stack<Person> &);
