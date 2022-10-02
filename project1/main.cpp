#include "main.h"

int main() {
    SongList list;
    int option = 0;

    std::cout.setf(std::ios::fixed, std::ios::floatfield);
    std::cout.precision(2);

    try {
        load_songs(list);
    }
    catch (const char * err) {
        std::cout << err << std::endl;
        return EXIT_FAILURE;
    }

    welcome();

    while ((option = menu()) != 1) {
        switch(option) {
            case 2:
                add(list);
                break;
            case 3:
                edit(list);
                break;
            case 4:
                display(list);
                break;
            case 5:
                display_artist(list);
                break;
            case 6:
                remove(list);
                break;
            default:
                std::cout << "Invalid option" << std::endl;
                return EXIT_FAILURE;
        }
     }

    std::cout << "[done]" << std::endl;

    return EXIT_SUCCESS;
}

void load_songs(SongList &list) {
    std::ifstream file;
    char * title = nullptr;
    char * artist = nullptr;
    double length = 0;
    long long likes = 0;
    Song song;

    file.open("songs.txt");
    if (!file) {
        throw "Error opening file \"songs.txt\"";
    }

    // Read in data from the file in format "title,artist,length,likes" and 
    // add it to the list
    while (!file.eof()) {
        title = get_name(file, ',');
        artist = get_name(file, ',');
        file >> length;
        file.ignore(1);
        file >> likes;
        file.ignore(2, '\n');

        song.set_title(title);
        delete[] title;
        song.set_artist(artist);
        delete[] artist;
        song.set_length(length);
        song.set_likes(likes);
        list.add(song);
    }
}

void welcome() {
    std::cout << "Welcome to Song List Manager! All input is case sensitive." << std::endl << std::endl;
}

int menu() {
    int option = 0;

    std::cout << std::endl
              << "Please enter one of the following options:" << std::endl
              << "1 - Quit the program" << std::endl
              << "2 - Add a new song to the list" << std::endl
              << "3 - Edit the number of likes for a song" << std::endl
              << "4 - Display current list" << std::endl
              << "5 - Display songs by an artist" << std::endl
              << "6 - Remove all songs with less than X likes" << std::endl
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

long long get_likes() {
    long long likes = 0;

    std::cin >> likes;
    while (std::cin.fail() || likes < 0) {
        std::cin.clear();
        std::cin.ignore(1024, '\n');
        std::cout << "Invalid number of likes" << std::endl;
        std::cout << "Enter number of likes: ";
        std::cin >> likes;
    }
    std::cin.ignore(2, '\n');

    return likes;
}

double get_length() {
    double length = 0;

    std::cin >> length;
    while (std::cin.fail() || length < 0) {
        std::cin.clear();
        std::cin.ignore(1024, '\n');
        std::cout << "Invalid length" << std::endl;
        std::cout << "Enter length: ";
        std::cin >> length;
    }
    std::cin.ignore(2, '\n');

    return length;
}

void add(SongList &list) {
    char * title = nullptr;
    char * artist = nullptr;
    double length = 0;
    long long likes = 0;
    Song song;

    std::cout << "Enter the title of the song (e.g. Let it Be): ";
    title = get_name(std::cin);

    std::cout << "Enter the artist of the song (e.g. The Beatles): ";
    artist = get_name(std::cin);

    std::cout << "Enter the length of the song (e.g. 3.08): ";
    length = get_length();

    std::cout << "Enter the number of likes for the song (e.g. 8000000): ";
    likes = get_likes();

    song.set_title(title);
    delete[] title;
    song.set_artist(artist);
    delete[] artist;
    song.set_length(length);
    song.set_likes(likes);

    list.add(song);
}

void edit(SongList &list) {
    char * title = nullptr;
    char * artist = nullptr;
    long long likes = 0;

    Song original_song;
    Song new_song;

    std::cout << "Enter the title of the song to edit (e.g. Let it Be): ";
    title = get_name(std::cin);

    std::cout << "Enter the artist of the song to edit (e.g. The Beatles): ";
    artist = get_name(std::cin);

    original_song.set_title(title);
    original_song.set_artist(artist);

    std::cout << "Searching for \"" << title << "\" - \"" << artist << "\" in list..." << std::endl;

    delete[] title;
    delete[] artist;

    try {
        new_song = list.remove(original_song);
    }
    catch (const char * err) {
        std::cout << err << std::endl;
        return;
    }

    std::cout << "Found!" << std::endl << std::endl;

    std::cout << "Enter the new number of likes: ";
    likes = get_likes();

    new_song.set_likes(likes);
    list.add(new_song);

    std::cout << "Song updated!" << std::endl;
}

void display(const SongList &list) {
    std::cout << std::endl << list << std::endl;
}

void display_artist(const SongList &list) {
    const char * artist = nullptr;

    std::cout << "Enter the artist to display (e.g. The Beatles): ";
    artist = get_name(std::cin);

    list.display_artist(artist);

    delete[] artist;
}

void remove(SongList &list) {
    long long likes = 0;

    std::cout << "Enter the minimum number of likes to remove (e.g. 10000): ";
    likes = get_likes();

    list.remove_with_fewer_likes(likes);
}