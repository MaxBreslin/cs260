#include "main.h"

/*
    Max Breslin - October 24st, 2022
    CS260 Data Structures
    Project 2

    This program will read in a file of people and add them to a queue and stack.
    It will then allow the user to add people to the queue and stack, remove
    people from the queue and stack, and display the queue and stack. Everytime a
    person is removed from the stack, their information will be written to 'promos.txt'.
*/

// main.cpp - main function and menu functions

int main() {
    Table<String, Website> table(23);
    table.set_hash_function(&hash_string);

    std::ifstream website_file_in;

    int option = 0;

    std::cout.setf(std::ios::fixed, std::ios::floatfield);
    std::cout.precision(2);

    website_file_in.open("websites.txt");
    if (!website_file_in) {
        std::cout << "Error opening file \'websites.txt\'" << std::endl;
        return EXIT_FAILURE;
    }

    load_websites(table, website_file_in);

    welcome();

    while ((option = menu()) != 1) {
        switch(option) {
            case 2:
                insert_website(table);
                break;
            case 3:
                retrieve_websites(table);
                break;
            case 4:
                edit_websites(table);
                break;
            case 5:
                remove_websites(table);
                break;
            case 6:
                display_websites(table);
                break;
            default:
                std::cout << "Invalid option" << std::endl;
                return EXIT_FAILURE;
        }
     }

    std::cout << "[done]" << std::endl;

    return EXIT_SUCCESS;
}

unsigned int hash_string(const String &string) {
    unsigned int hash = 0x811C9DC5;
    size_t length = string.length();

    for (size_t i = 0; i < length; i ++) {
        hash *= 0x1000193;
        hash ^= string[i];
    }   

    return hash;
}

void load_websites(Table<String, Website> &table, std::ifstream &file) {
    String topic;
    String address;
    String summary;
    String review;
    int rating = 0;

    Website website;

    // Read in data from the file in format "topic,address,summary,review,rating" and 
    // add it to the table
    while (!file.eof()) {
        topic.getline(file, ',');
        address.getline(file, ',');
        summary.getline(file, ',');
        review.getline(file, ',');
        file >> rating;
        file.ignore(2, '\n');

        website.set_topic(topic);
        website.set_address(address);
        website.set_summary(summary);
        website.set_review(review);
        website.set_rating(rating);

        table.insert(topic, website);
    }
}

void welcome() {
    std::cout << "Welcome to Website Table Manager! All input is case sensitive." << std::endl << std::endl;
}

int menu() {
    int option = 0;

    std::cout << std::endl
              << "Please enter one of the following options:" << std::endl
              << "1 - Quit the program" << std::endl
              << "2 - Add a new webiste to the table" << std::endl
              << "3 - Display all websites with a certain topic" << std::endl
              << "4 - Edit all websites with a certain topic" << std::endl
              << "5 - Remove all websites with a certain topic" << std::endl
              << "6 - Display websites" << std::endl
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

void insert_website(Table<String, Website> &table) {
    String topic;
    String address;
    String summary;
    String review;
    int rating = 0;

    Website website;

    std::cout << "Enter the topic of the website: ";
    topic.getline(std::cin);
    std::cout << "Enter the address of the website: ";
    address.getline(std::cin);
    std::cout << "Enter the summary of the website: ";
    summary.getline(std::cin);
    std::cout << "Enter the review of the website: ";
    review.getline(std::cin);
    std::cout << "Enter the rating of the website: ";
    std::cin >> rating;
    while (std::cin.fail() || rating < 1 || rating > 5) {
        std::cin.clear();
        std::cin.ignore(1024, '\n');
        std::cout << "Invalid rating" << std::endl;
        std::cout << "Enter the rating of the website: ";
        std::cin >> rating;
    }
    std::cin.ignore(2, '\n');

    website.set_topic(topic);
    website.set_address(address);
    delete[] address;
    website.set_summary(summary);
    delete[] summary;
    website.set_review(review);
    delete[] review;
    website.set_rating(rating);

    table.insert(topic, website);
    delete[] topic;
}

void retrieve_websites(Table<String, Website> &table) {
    String topic = nullptr;

    std::cout << "Enter the topic of the website(s): ";
    topic.getline(std::cin);

    List<Website> websites = table.retrieve(topic);
    std::cout << websites;
    if (websites.length()) {
        std::cout << websites << std::endl;
    }
    else {
        std::cout << "No websites with topic \'" << topic << "\' found" << std::endl;
    }

    delete[] topic;
}

void edit_websites(Table<String, Website> &table) {
    String topic = nullptr;
    String review = nullptr;
    int rating = 0;

    Website website;
    Website new_website;

    size_t index = 0;

    std::cout << "Enter the topic of the website(s) to edit: ";
    topic.getline(std::cin);

    List<Website> websites = table.retrieve(topic);

    if (websites.length()) {
        std::cout << websites << std::endl;

        std::cout << "Enter which website to edit (e.g. 1): ";
        std::cin >> index;
        while (std::cin.fail() || index < 1 || index > websites.length()) {
            std::cin.clear();
            std::cin.ignore(1024, '\n');
            std::cout << "Invalid index" << std::endl;
            std::cout << "Enter which website to edit (e.g. 1): ";
            std::cin >> index;
        }
        std::cin.ignore(2, '\n');

        website = websites[index - 1];
        new_website = website;

        std::cout << "Enter the new review for the website: ";
        review.getline(std::cin);
        std::cout << "Enter the new rating for the website: ";
        std::cin >> rating;
        while (std::cin.fail() || rating < 1 || rating > 5) {
            std::cin.clear();
            std::cin.ignore(1024, '\n');
            std::cout << "Invalid rating" << std::endl;
            std::cout << "Enter the new rating for the website: ";
            std::cin >> rating;
        }
        std::cin.ignore(2, '\n');

        new_website.set_review(review);
        delete[] review;
        new_website.set_rating(rating);

        table.edit(topic, website, new_website);
    }
    else {
        std::cout << "No websites with topic \'" << topic << "\' found" << std::endl;
    }

    delete[] topic;
}

void remove_websites(Table<String, Website> &table) {
    String topic = nullptr;

    std::cout << "Enter the topic of the website(s) to remove: ";
    topic.getline(std::cin);

    List<Website> websites = table.retrieve(topic);

    if (websites.length()) {
        std::cout << websites << std::endl;

        table.remove(topic);
    }
    else {
        std::cout << "No websites with topic \'" << topic << "\' found" << std::endl;
    }

    delete[] topic;
}

void display_websites(Table<String, Website> &table) {
    std::cout << table << std::endl;
}
