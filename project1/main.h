// main.h - main function and menu functions

#pragma once

#include "songlist.h"

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

// Reads a long long from std::cin and continues to prompt
// the user until a valid long long is entered. Returns the
// valid long long.
long long get_likes();

// Reads a double from std::cin and continues to prompt
// the user until a valid double is entered. Returns the
// valid double.
double get_length();

// Opens the file "songs.txt" and reads the sontents into
// the passed SongList. If "songs.txt" cannot be opened,
// throws a const char *.
// Parameters:
//    list - the SongList to read the songs into
void load_songs(SongList &);

// Prompts the user for information about
// a new Song and adds it to the passed SongList
// Parameters:
//     list - the SongList to add the new Song to
void add(SongList &);

// Prompts the user for information about the Song to edit
// and the new number of likes for the Song. If the Song
// is found, the number of likes is updated. Otherwise,
// displays a message indicating that the Song was not found
// and returns.
// Parameters:
//     list - the SongList to edit
void edit(SongList &);

// Displays the contents of the passed SongList to std::cout
// Parameters:
//     list - the SongList to display
void display(const SongList &);

// Prompts the user for an artist and displays all Songs
// by that artist
// Parameters:
//     list - the SongList to search
void display_artist(const SongList &);

// Prompts the user for a number of likes and removes all
// Songs with less than that number from the passed SongList
// Parameters:
//     list - the SongList to remove Songs from
void remove(SongList &);
