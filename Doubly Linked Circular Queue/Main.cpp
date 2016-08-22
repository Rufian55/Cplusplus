/****************************************************************************************
** Program Filename: Main.cpp
** Author: Chris Kearns
** Date: 2/28/2016
** Description: Queue class demonstration file that initializes and manipulates a doubly
** linked circular Queue with respective addBack() getFront() and removeFront() functions.
** Input: user run program.
** Output: cout to console.
*****************************************************************************************/
#include "Queue.hpp"
#include<string>
using std::string;
#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
	int choice;
	string userChoice;
	string a = "a)";
	string b = "b)";
	string c = "c)";
	string d = "d)";
	string x = "x)";
	Queue chrisQueue;
	int var;

	while (true) {
		cout << "\nWelcome to the Doubly Linked Circular List Demo!\n"
			<< "a) Enter a value\n"
			<< "b) Display first value\n"
			<< "c) Remove a value\n"
			<< "d) Display the queue contents\n"
			<< "x) Exit\n"
			<< "Please enter your choice by typing \"x)\" and pressing \"<Enter>\", for example.\n";
		cin >> userChoice;
		cin.ignore();
		while (userChoice != a && userChoice != b && userChoice != c && userChoice != d && userChoice != x) {
			cout << "You have entered your choice incorrectly! Please try again.\n"
				<< "a) Enter a value\n"
				<< "b) Display first value\n"
				<< "c) Remove a value\n"
				<< "d) Display the queue contents\n"
				<< "x) Exit\n"
				<< "Please enter your choice by typing \"x)\" and pressing \"<Enter>\", for example.\n";
			cin >> userChoice;
			cin.ignore();
		}

		// Map userChoice string to choice int.
		if (userChoice == a) {
			choice = 1;
		} else if (userChoice == b) {
			choice = 2;
		} else if (userChoice == c) {
			choice = 3;
		} else if (userChoice == d) {
			choice = 4;
		} else if (userChoice == x) {
			choice = 5;
		}

		// Invoke appropriate function.
		switch (choice) {
		case 1:
			cout << "Please enter your int!\n";
			cin >> var;
			while (!cin || var < 0) {
				cin.clear();
				cin.ignore();
				cout << "Enter an int > -1 and no strings!!\n";
				cin >> var;
			}
			chrisQueue.addBack(var);
			break;
		case 2:
			cout << chrisQueue.getFront() << "\n";
			break;
		case 3:
			if (chrisQueue.removeFront() == -1) {
				cout << "Only the current front QueueNode value is removed!!\n\n";
			}
			break;
		case 4:
			chrisQueue.showList();
			break;
		case 5:
			exit(1);
		}
	}
}
