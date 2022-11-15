#pragma once

// main.h - main function declarations

#include "table.h"
#include "website.h"
#include <fstream>

int main();

// An implementation of the FNV-1 hash function
unsigned int hash_string(const String &);

// Load websites from a file into a table
void load_websites(Table<String, Website> &, std::ifstream &);

// Displays a welcome message
void welcome();

// Displays a menu, prompts the user to choose an option,
// and returns the user's choice
int menu();

// Prompts the user to enter a website topic, address, summary,
// review, and rating, and inserts the website into the table
void insert_website(Table<String, Website> &);

// Prompts the user to enter a website topic, and displays
// all websites in the passed table with that topic
void retrieve_websites(Table<String, Website> &);

// Prompts the user to enter a website topic and displays all
// websites in the passed table with that topic. If there are
// any websites with that topic, the user is prompted to choose
// a website to edit. The user is then prompted to enter a new
// review and rating for the website, and the website is updated
// in the table
void edit_websites(Table<String, Website> &);

// Prompts the user to enter a website topic and removes all
// websites in the passed table with that topic
void remove_websites(Table<String, Website> &);

// Displays all websites in the passed table
void display_websites(Table<String, Website> &);
