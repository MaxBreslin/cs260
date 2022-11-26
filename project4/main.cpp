// main.cpp - main function and menu functions

#include "main.hpp"

/*
    Max Breslin - November 14st, 2022
    CS260 Data Structures
    Project 3

    This program will read in a file of websites and add them to a hash table.
    It will then allow the user to add websites to the table, remove websites
    from the table, edit websites in the table, and display all websites in the
    table.
*/

int main() {
    RedBlackTree<int, int> test;

    test.insert(5, 5);
    test.insert(6, 6);
    test.insert(3, 3);
    test.insert(4, 4);
    test.insert(7, 7);
    test.insert(8, 8);
    test.insert(2, 2);

    std::cout << test << std::endl;

    std::cout << "height: " << test.height() << std::endl;
    std::cout << "max width: " << test.max_width() << std::endl;

    // Table<String, Website> table(23);
    // table.set_hash_function(&hash_string);

    // std::ifstream website_file_in;

    // int option = 0;

    // std::cout.setf(std::ios::fixed, std::ios::floatfield);
    // std::cout.precision(2);

    // website_file_in.open("websites.txt");
    // if (!website_file_in) {
    //     std::cout << "Error opening file \'websites.txt\'" << std::endl;
    //     return EXIT_FAILURE;
    // }

    // load_websites(table, website_file_in);

    // welcome();

    // while ((option = menu()) != 1) {
    //     switch(option) {
    //         case 2:
    //             insert_website(table);
    //             break;
    //         case 3:
    //             retrieve_websites(table);
    //             break;
    //         case 4:
    //             edit_websites(table);
    //             break;
    //         case 5:
    //             remove_websites(table);
    //             break;
    //         case 6:
    //             display_websites(table);
    //             break;
    //         default:
    //             std::cout << "Invalid option" << std::endl;
    //             return EXIT_FAILURE;
    //     }
    //  }

    // std::cout << "[done]" << std::endl;

    return EXIT_SUCCESS;
}

// unsigned int hash_string(const String &string) {
//     unsigned int hash = 0x811C9DC5;
//     size_t length = string.length();

//     for (size_t i = 0; i < length; i ++) {
//         hash *= 0x1000193;
//         hash ^= string[i];
//     }   

//     return hash;
// }

// void load_websites(Table<String, Website> &table, std::ifstream &file) {
//     String topic;
//     String address;
//     String summary;
//     String review;
//     int rating = 0;

//     Website website;

//     // Read in data from the file in format "topic,address,summary,review,rating" and 
//     // add it to the table
//     while (!file.eof()) {
//         topic.get_line(file, ',');
//         address.get_line(file, ',');
//         summary.get_line(file, ',');
//         review.get_line(file, ',');
//         file >> rating;
//         file.ignore(2, '\n');

//         website.set_topic(topic);
//         website.set_address(address);
//         website.set_summary(summary);
//         website.set_review(review);
//         website.set_rating(rating);

//         table.insert(topic, website);
//     }
// }

// void welcome() {
//     std::cout << "Welcome to Website Table Manager! All input is case sensitive." << std::endl << std::endl;
// }

// int menu() {
//     int option = 0;

//     std::cout << std::endl
//               << "Please enter one of the following options:" << std::endl
//               << "1 - Quit the program" << std::endl
//               << "2 - Add a new webiste to the table" << std::endl
//               << "3 - Display all websites with a certain topic" << std::endl
//               << "4 - Edit a website with a certain topic" << std::endl
//               << "5 - Remove all websites with a certain topic" << std::endl
//               << "6 - Display websites" << std::endl
//               << "Enter option: ";

//     std::cin >> option;
//     while (std::cin.fail() || option < 1 || option > 6) {
//         std::cin.clear();
//         std::cin.ignore(1024, '\n');
//         std::cout << "Invalid option" << std::endl;
//         std::cout << "Enter option: ";
//         std::cin >> option;
//     }
//     std::cin.ignore(2, '\n');

//     std::cout << std::endl;

//     return option;
// }

// void insert_website(Table<String, Website> &table) {
//     String topic;
//     String address;
//     String summary;
//     String review;
//     int rating = 0;

//     Website website;

//     std::cout << "Enter the topic of the website: ";
//     topic.get_line(std::cin);
//     std::cout << "Enter the address of the website: ";
//     address.get_line(std::cin);
//     std::cout << "Enter the summary of the website: ";
//     summary.get_line(std::cin);
//     std::cout << "Enter the review of the website: ";
//     review.get_line(std::cin);
//     std::cout << "Enter the rating of the website: ";
//     std::cin >> rating;
//     while (std::cin.fail() || rating < 1 || rating > 5) {
//         std::cin.clear();
//         std::cin.ignore(1024, '\n');
//         std::cout << "Invalid rating" << std::endl;
//         std::cout << "Enter the rating of the website: ";
//         std::cin >> rating;
//     }
//     std::cin.ignore(2, '\n');

//     website.set_topic(topic);
//     website.set_address(address);
//     website.set_summary(summary);
//     website.set_review(review);
//     website.set_rating(rating);

//     table.insert(topic, website);
// }

// void retrieve_websites(Table<String, Website> &table) {
//     String topic;

//     std::cout << "Enter the topic of the website(s): ";
//     topic.get_line(std::cin);

//     List<Website> websites = table.retrieve(topic);
//     if (websites.length()) {
//         std::cout << websites << std::endl;
//     }
//     else {
//         std::cout << "No websites with topic \'" << topic << "\' found" << std::endl;
//     }
// }

// void edit_websites(Table<String, Website> &table) {
//     String topic;
//     String review;
//     int rating = 0;

//     Website website;
//     Website new_website;

//     size_t index = 0;

//     std::cout << "Enter the topic of the website(s) to edit: ";
//     topic.get_line(std::cin);

//     List<Website> websites = table.retrieve(topic);

//     if (websites.length()) {
//         std::cout << websites << std::endl;

//         std::cout << "Enter which website to edit (e.g. 1): ";
//         std::cin >> index;
//         while (std::cin.fail() || index < 1 || index > websites.length()) {
//             std::cin.clear();
//             std::cin.ignore(1024, '\n');
//             std::cout << "Invalid index" << std::endl;
//             std::cout << "Enter which website to edit (e.g. 1): ";
//             std::cin >> index;
//         }
//         std::cin.ignore(2, '\n');

//         website = websites[index - 1];
//         new_website = website;

//         std::cout << "Enter the new review for the website: ";
//         review.get_line(std::cin);
//         std::cout << "Enter the new rating for the website: ";
//         std::cin >> rating;
//         while (std::cin.fail() || rating < 1 || rating > 5) {
//             std::cin.clear();
//             std::cin.ignore(1024, '\n');
//             std::cout << "Invalid rating" << std::endl;
//             std::cout << "Enter the new rating for the website: ";
//             std::cin >> rating;
//         }
//         std::cin.ignore(2, '\n');

//         new_website.set_review(review);
//         new_website.set_rating(rating);

//         table.edit(topic, website, new_website);
//     }
//     else {
//         std::cout << "No websites with topic \'" << topic << "\' found" << std::endl;
//     }
// }

// void remove_websites(Table<String, Website> &table) {
//     String topic;

//     std::cout << "Enter the topic of the website(s) to remove: ";
//     topic.get_line(std::cin);

//     List<Website> websites = table.retrieve(topic);

//     if (websites.length()) {
//         std::cout << "Removed: " << std::endl << websites << std::endl;

//         table.remove(topic);
//     }
//     else {
//         std::cout << "No websites with topic \'" << topic << "\' found" << std::endl;
//     }
// }

// void display_websites(Table<String, Website> &table) {
//     std::cout << table << std::endl;
// }
