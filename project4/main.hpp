#pragma once

// main.hpp - main function declarations

#include "avltree.hpp"
#include "website.hpp"
#include <fstream>

int main();

// Load websites from a file into a tree
void load_websites(AVLTree<String, Website> &, std::ifstream &);

// Displays a welcome message
void welcome();

// Displays a menu, prompts the user to choose an option,
// and returns the user's choice
int menu();

// Prompts the user to enter a website topic, keyword, address,
// summary, review, and rating, and inserts the website into the tree
void insert_website(AVLTree<String, Website> &);

// Prompts the user to enter a website keyword and displays
// the website in the passed tree with that keyword
void retrieve_website(AVLTree<String, Website> &);

// Prompts the user to enter a website keyword and removes
// the website in the passed tree with that keyword.
// Displays the removed website.
void remove_website(AVLTree<String, Website> &);

// Prompts the user to enter a website topic and removes all
// websites in the passed tree with that topic
void remove_websites(AVLTree<String, Website> &);

// Displays all websites in the passed tree in alphabetical order
void display_websites(AVLTree<String, Website> &);

// Displays the passed tree, including height and max width
void display_tree(AVLTree<String, Website> &);
