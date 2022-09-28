#pragma once

#include "songlist.h"

int main();

void welcome();

int menu();

char * get_name(std::istream &, const char);

void load_songs(SongList &);

// Prompts the user for information about
// a new item and adds it to the passed list
void add(SongList &);

// Prompts the user for information about
// the item(s) to update and calls the appropriate
// update function
void edit(SongList &);

// Prints the contents of the list to std::cout
void display(const SongList &);

void display_artist(const SongList &);

void remove(SongList &);