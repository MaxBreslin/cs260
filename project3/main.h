#pragma once

#include "table.h"
#include "website.h"
#include <fstream>

int main();

unsigned int hash_string(const String &);

void load_websites(Table<String, Website> &, std::ifstream &);

// Displays a welcome message
void welcome();

// Displays a menu, prompts the user to choose an option,
// and returns the user's choice
int menu();

void insert_website(Table<String, Website> &);

void retrieve_websites(Table<String, Website> &);

void edit_websites(Table<String, Website> &);

void remove_websites(Table<String, Website> &);

void display_websites(Table<String, Website> &);
