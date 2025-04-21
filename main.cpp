#include <iostream>
#include <string>
#include "ItemTracker.h"

void DisplayMenu() {
    std::cout << "\n========= Corner Grocer Menu =========" << std::endl;
    std::cout << "1. Search for an item’s purchase frequency" << std::endl;
    std::cout << "2. Display frequency of all items" << std::endl;
    std::cout << "3. Display histogram of item frequencies" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "=======================================" << std::endl;
    std::cout << "Enter your choice (1-4): ";
}

int main() {
    ItemTracker tracker("CS210_Project_Three_Input_File.txt", "frequency.dat");

    int choice;
    std::string userItem;

    while (true) {
        DisplayMenu();
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear(); // clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
            std::cout << "Invalid input. Please enter a number between 1 and 4." << std::endl;
            continue;
        }

        switch (choice) {
        case 1:
            std::cout << "Enter the item to search for: ";
            std::cin >> userItem;
            std::cout << userItem << " was purchased " << tracker.GetItemFrequency(userItem) << " times." << std::endl;
            break;

        case 2:
            std::cout << "\nItem Purchase Frequencies:\n";
            tracker.PrintAllFrequencies();
            break;

        case 3:
            std::cout << "\nItem Frequency Histogram:\n";
            tracker.PrintHistogram();
            break;

        case 4:
            std::cout << "Exiting program. Goodbye!" << std::endl;
            return 0;

        default:
            std::cout << "Invalid choice. Please enter a number between 1 and 4." << std::endl;
            break;
        }
    }

    return 0;
}
