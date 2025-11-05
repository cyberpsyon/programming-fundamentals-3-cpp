/**
 * Author: Ben Mickens
 * Date: 11-02-2025
 * Purpose: Implementation of browser history simulation functions.
 */

#include "BrowserHistory.hpp"

 // Display the main menu options to the user
void displayMenu() {
    cout << "Menu Options:" << endl;
    cout << "1. Visit a new page" << endl;
    cout << "2. Go back" << endl;
    cout << "3. Show current page" << endl;
    cout << "4. Show all visited pages" << endl;
    cout << "5. Quit" << endl;
    cout << "Enter your choice: ";
}


// Gets and validates menu choice from user

int getMenuChoice() {
    int choice;

    // Validate input
    while (!(cin >> choice)) {
        cin.clear(); // Clear error flags
        cin.ignore(10000, '\n'); // Discard invalid input
        cout << "\nInvalid input. Please enter a number (1-5): ";
    }

    cin.ignore(10000, '\n'); // Clear input buffer
    return choice;
}

//Prompt user for a website name and pushes it onto the stack
void visitPage(stack<string>& history) {
    string website;

    cout << "\nEnter website name (e.g., YouTube.com): ";
    getline(cin, website);

    // Validate that user entered something
    if (website.empty()) {
        cout << "No website entered." << endl;
        return;
    }

    // Push the new page onto the stack
    history.push(website);
    cout << "Visited: " << website << endl;
}

// Pops the most recent page from the stack to simulate going back
void goBack(stack<string>& history) {
    // Check if stack is empty or has only one page
    if (history.empty()) {
        cout << "\nNo pages to go back to. Your history is empty." << endl;
        return;
    }

    if (history.size() == 1) {
        cout << "\nYou're at the first page. Cannot go back further." << endl;
        return;
    }

    // Pop the current page to reveal the previous one
    string currentPage = history.top();
    history.pop();
    cout << "\nWent back from: " << currentPage << endl;
}

// Displays the page at the top of the stack (current page)
void showCurrentPage(const stack<string>& history) {
    // Handle empty stack case
    if (history.empty()) {
        cout << "Current Page: No pages visited yet" << endl;
        return;
    }

    // Display the top page without removing it
    cout << "Current Page: " << history.top() << endl;
}

// Displays all pages in the stack from most recent to oldest
void showAllPages(stack<string> history) {
    // Check if history is empty
    if (history.empty()) {
        cout << "\nBrowsing History: No pages visited yet" << endl;
        return;
    }

    cout << "\nBrowsing History (Most Recent to Oldest):" << endl;
    cout << "----------------------------------------" << endl;

    int position = 1;

    // Pop and display each page from the copied stack
    while (!history.empty()) {
        cout << position << ". " << history.top() << endl;
        history.pop();
        position++;
    }
}