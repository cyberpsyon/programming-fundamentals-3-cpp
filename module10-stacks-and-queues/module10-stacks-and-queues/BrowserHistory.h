/**
 * Author: Ben Mickens
 * Date: 11-02-2025
 * Purpose: Header file declaring functions for browser history simulation using STL stack.
 */

#ifndef BROWSERHISTORY_H
#define BROWSERHISTORY_H

#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function declarations
void displayMenu();
void visitPage(stack<string>& history);
void goBack(stack<string>& history);
void showCurrentPage(const stack<string>& history);
void showAllPages(stack<string> history);
int getMenuChoice();

#endif