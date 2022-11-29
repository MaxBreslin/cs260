#pragma once

// main.h - main function declarations

#include "avltree.hpp"
#include "website.hpp"
#include <fstream>

int main();

// Load websites from a file into a table
void load_websites(AVLTree<String, Website> &, std::ifstream &);

// Displays a welcome message
void welcome();

// Displays a menu, prompts the user to choose an option,
// and returns the user's choice
int menu();

// Prompts the user to enter a website topic, address, summary,
// review, and rating, and inserts the website into the table
void insert_website(AVLTree<String, Website> &);

// Prompts the user to enter a website topic, and displays
// all websites in the passed table with that topic
void retrieve_website(AVLTree<String, Website> &);

void remove_website(AVLTree<String, Website> &);

// Prompts the user to enter a website topic and removes all
// websites in the passed table with that topic
void remove_websites(AVLTree<String, Website> &);

// Displays all websites in the passed table
void display_websites(AVLTree<String, Website> &);

void display_tree(AVLTree<String, Website> &);
