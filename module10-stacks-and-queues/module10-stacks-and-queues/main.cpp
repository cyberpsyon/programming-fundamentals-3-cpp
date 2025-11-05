/**
 * Author: Ben Mickens
 * Date: 11-02-2025
 * Purpose: This program simulates a web browser's back button functionality using an STL stack to manage browsing history.
 */

#include "BrowserHistory.hpp"

int main() {
    stack<string> browserHistory; // Stack to hold visited websites
    int choice;
    bool running = true;

    cout << "===== Browser History Simulator =====" << endl <<endl;

    // Main program loop (continues until user chooses to quit)
    while (running) {
        displayMenu();
        choice = getMenuChoice();

        // Get user's menu selection
        switch (choice) {
        case 1:
            // Visit a new page (push onto stack)
            visitPage(browserHistory);
            break;

        case 2:
            // Go back (pop from stack)
            goBack(browserHistory);
            break;

        case 3:
            // Show current page (peek at top of stack)
            showCurrentPage(browserHistory);
            break;

        case 4:
            // Show all visited pages (display entire stack)
            showAllPages(browserHistory);
            break;

        case 5:
            // Quit the program
            cout << "\nClosing browser... Goodbye!" << endl;
            running = false;
            break;

        default:
            // Input validation
            cout << "\nInvalid choice. Please select 1-5." << endl;
            break;
        }

        // Display current page after each action (except quit)
        if (running && choice >= 1 && choice <= 4) {
            cout << "\n";
            showCurrentPage(browserHistory);
            cout << "----------------------------------------" << endl << endl;
        }
    }

    return 0;
}