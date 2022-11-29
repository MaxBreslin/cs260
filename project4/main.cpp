// main.cpp - main function and menu functions

#include "main.hpp"

/*
    Max Breslin - November 24th, 2022
    CS260 Data Structures
    Project 4

    This program will read in a file of websites and add them to an AVL tree.
    It will then allow the user to add websites to the tree, remove websites
    from the tree, display websites in the tree, and display the tree itself.
*/

int main() {
    AVLTree<String, Website> tree;

    std::ifstream website_file_in;

    int option = 0;

    std::cout.setf(std::ios::fixed, std::ios::floatfield);
    std::cout.precision(2);

    website_file_in.open("websites.txt");
    if (!website_file_in) {
        std::cout << "Error opening file \'websites.txt\'" << std::endl;
        return EXIT_FAILURE;
    }

    load_websites(tree, website_file_in);

    welcome();

    while ((option = menu()) != 1) {
        switch(option) {
            case 2:
                insert_website(tree);
                break;
            case 3:
                retrieve_website(tree);
                break;
            case 4:
                remove_website(tree);
                break;
            case 5:
                remove_websites(tree);
                break;
            case 6:
                display_websites(tree);
                break;
            case 7:
                display_tree(tree);
                break;
            default:
                std::cout << "Invalid option" << std::endl;
                return EXIT_FAILURE;
        }
     }

    std::cout << "[done]" << std::endl;

    return EXIT_SUCCESS;
}

void load_websites(AVLTree<String, Website> &tree, std::ifstream &file) {
    String topic;
    String keyword;
    String address;
    String summary;
    String review;
    int rating = 0;

    Website website;

    // Read in data from the file in format "topic,keyword,address,summary,review,rating" and 
    // add it to the table
    while (!file.eof()) {
        topic.get_line(file, ',');
        keyword.get_line(file, ',');
        address.get_line(file, ',');
        summary.get_line(file, ',');
        review.get_line(file, ',');
        file >> rating;
        file.ignore(2, '\n');

        website.set_topic(topic);
        website.set_keyword(keyword);
        website.set_address(address);
        website.set_summary(summary);
        website.set_review(review);
        website.set_rating(rating);

        tree.insert(keyword, website);
    }
}

void welcome() {
    std::cout << "Welcome to Website Tree Manager! All input is case sensitive." << std::endl << std::endl;
}

int menu() {
    int option = 0;

    std::cout << std::endl
              << "Please enter one of the following options:" << std::endl
              << "1 - Quit the program" << std::endl
              << "2 - Add a new webiste to the tree" << std::endl
              << "3 - Display a website with a certain keyword" << std::endl
              << "4 - Remove a website with a certain keyword" << std::endl
              << "5 - Remove all websites with a certain topic" << std::endl
              << "6 - Display all websites" << std::endl
              << "7 - Display tree (with height and max width)" << std::endl
              << "Enter option: ";

    std::cin >> option;
    while (std::cin.fail() || option < 1 || option > 7) {
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

void insert_website(AVLTree<String, Website> &tree) {
    String topic;
    String keyword;
    String address;
    String summary;
    String review;
    int rating = 0;

    Website website;

    std::cout << "Enter the topic of the website (e.g. cars): ";
    topic.get_line(std::cin);
    std::cout << "Enter the keyword for the website (e.g. nba - should be unique): ";
    keyword.get_line(std::cin);
    std::cout << "Enter the address of the website (e.g. https://stackoverflow.com/): ";
    address.get_line(std::cin);
    std::cout << "Enter the summary of the website (e.g. The Gmail homepage): ";
    summary.get_line(std::cin);
    std::cout << "Enter the review of the website (e.g. A little disorganized): ";
    review.get_line(std::cin);
    std::cout << "Enter the rating of the website (e.g. 3): ";
    std::cin >> rating;
    while (std::cin.fail() || rating < 1 || rating > 5) {
        std::cin.clear();
        std::cin.ignore(1024, '\n');
        std::cout << "Invalid rating" << std::endl;
        std::cout << "Enter the rating of the website (e.g. 3): ";
        std::cin >> rating;
    }
    std::cin.ignore(2, '\n');

    website.set_topic(topic);
    website.set_keyword(keyword);
    website.set_address(address);
    website.set_summary(summary);
    website.set_review(review);
    website.set_rating(rating);

    tree.insert(keyword, website);
}

void retrieve_website(AVLTree<String, Website> &tree) {
    String keyword;

    std::cout << "Enter the keyword for the website (e.g. nba): ";
    keyword.get_line(std::cin);

    try {
        Website website = tree.retrieve(keyword);
        std::cout << website << std::endl;
    }
    catch (const char * e) {
        std::cout << e << std::endl;
        return;
    }
}

void remove_website(AVLTree<String, Website> &tree) {
    String keyword;

    std::cout << "Enter the keyword for the website to remove (e.g. nba): ";
    keyword.get_line(std::cin);

    try {
        Website removed = tree.remove(keyword);
        std::cout << "Removed website: " << std::endl << removed << std::endl;
    }
    catch (const char * e) {
        std::cout << e << std::endl;
        return;
    }
}

void remove_websites(AVLTree<String, Website> &tree) {
    String topic;

    std::cout << "Enter the topic for the website(s) to remove (e.g. cars): ";
    topic.get_line(std::cin);

    List<Website> removed;
    List<Website> websites = tree.retrieve_all();
    for (size_t i = 0; i < websites.length(); i ++) {
        if (websites[i].get_topic() == topic) {
            removed.insert(tree.remove(websites[i].get_keyword()));
        }
    }

    if (removed.length()) {
        std::cout << "Removed website(s): " << std::endl;
        std::cout << removed << std::endl;
    }
    else {
        std::cout << "No websites with that topic were found" << std::endl;
    }
}

void display_websites(AVLTree<String, Website> &tree) {
    std::cout << tree << std::endl;
}

void display_tree(AVLTree<String, Website> &tree) {
    tree.display();
    std::cout << std::endl 
              << "Height: " << tree.height() << std::endl 
              << "Max width: " << tree.max_width() << std::endl;   
}