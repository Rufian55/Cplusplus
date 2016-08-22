/****************************************************************************************
** Program Filename: Main.cpp
** Author: Chris Kearns (CS-162-400 W2016 LAB_6)
** Date: 2/14/2016
** Description: Stack and Queue class demonstration file that initializes and
** manipulates a stack and a queue with respective add and remove functions.
** Input: user run program.
** Output: cout to console.
*****************************************************************************************/
#include "Stack.hpp"
#include "Queue.hpp"
#include<cstddef>
#include<string>
using std::string;
#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
	int answer;					// Local cin collection var.
	int choice;					// Local cin collection var
	int removedVar;				// Used to collect and cout stack variables.
	int removedVar1;			// Used for dual removal in Manual Section.
	int removedVar2;			// Used for dual removal in Manual Section.
	int i;						// for loop control var.
	int aVar;					// Used to collect and cout queue variables.
	int anInt;					// Used to add ints to chrisStack and chrisQueue in Manual Section.
	string manControl = "n";	// Manaul Section while loop quit control var.

	// Demonstrate Stack FIFO operation! 
	Stack chrisStack;

	//Demonstrate adding nodes to the stack.
	cout << endl << "DEMONSTRATION PROGRAM FOR A SIMPLE DYNAMIC STACK AND QUEUE!" << endl << endl;
	cout << "Add the years the NY Giants won the Superbowl!" << endl << endl;

	cout << "Now adding 1986" << endl;
	chrisStack.add(1986);

	cout << "Now adding 1990" << endl;
	chrisStack.add(1990);

	cout << "Now adding 2007" << endl;
	chrisStack.add(2007);

	cout << "Now adding 2011" << endl;
	chrisStack.add(2011);

	//Demonstrate removing nodes from the stack.
	cout << endl << "Remove the years the NY Giants won the Superbowl!" << endl << endl;

	cout << "Now removing 2011" << endl;
	chrisStack.remove(removedVar);
	cout << "Removed " << removedVar << endl;

	cout << "Now removing 2007" << endl;
	chrisStack.remove(removedVar);
	cout << "Removed " << removedVar << endl;

	cout << "Now removing 1990" << endl;
	chrisStack.remove(removedVar);
	cout << "Removed " << removedVar << endl;

	cout << "Now removing 1986" << endl;
	chrisStack.remove(removedVar);
	cout << "Removed " << removedVar << endl << endl;

	cout << "Note the ints came off the stack in FILO order." << endl;
	cout << "Stack chrisStack is now empty, but would you like to attempt to remove again?" << endl;
	cout << "Enter 1 to attempt or any other character to move onto to the queue demo." << endl;
	cin >> answer;

	cout << endl;

	if (answer == 1) {
		cout << endl << "Attempting to remove 2000, the year the NY Giants lost the Superbowl!" << endl;
		chrisStack.remove(removedVar);
	}


	// Demonstrate the Queue class operation!
	Queue chrisQueue;

	// "Enqueue" (add) some ints to chrisQueue.
	cout << "Adding ints 10, 20 , 30, 40 , 50, 60, 70, 80, 90, and 100 to the" << endl
		<< " back of chrisQueue, in that order!" << endl << endl;
	for (i = 10; i < 101; i += 10) {
		chrisQueue.add(i);
	}

	// "Dequeue" (remove) and display all ints in the queue.
	cout << "Removing ints from Queue chrisQueue from the front of chrisQueue!" << endl << endl;
	while (!chrisQueue.isEmpty()) {
		chrisQueue.remove(aVar);
		cout << "Node removed from chrisQueue contained the var " << aVar << "." << endl;
	}
	cout << endl << "Note the ints were removed in the same order they went in (FIFO)." << endl;
	cout << "Queue chrisQueue is now empty, but would you like to attempt to remove again?" << endl;
	cout << "Enter 1 to attempt or any other character to move onto to the Manual Demo." << endl;
	cin >> answer;

	cout << endl;

	if (answer == 1) {
		cout << "We will now attempt to remove from the empty Queue chrisQueue!" << endl << endl;
		chrisQueue.remove(aVar);
	}

	// Manual add and remove section.
	while (manControl != "q") {
		choice = 0;
		cout << endl;
		cout << "MANUAL ADD/REMOVE FROM chrisStack, chrisQueue, OR BOTH!" << endl;
		cout << "Enter 1 to add to chrisStack." << endl;
		cout << "Enter 2 to remvoe from chrisStack." << endl;
		cout << "Enter 3 to add to chrisQueue." << endl;
		cout << "Enter 4 to remove from chrisQueue." << endl;
		cout << "Enter 5 to add to both chrisStack and chrisQueue." << endl;
		cout << "Enter 6 to remove from both chrisStack and chrisQueue." << endl;
		cout << "or Enter 0 to quit" << endl;
		cin >> choice;

		if (choice == 0) { exit(EXIT_SUCCESS); }

		// User input validation.
		while (choice < 0 || choice > 6) {
			cout << "ERROR!" << endl;
			cout << "Enter 1 to add to chrisStack." << endl;
			cout << "Enter 2 to remvoe from chrisStack." << endl;
			cout << "Enter 3 to add to chrisQueue." << endl;
			cout << "Enter 4 to remove from chrisQueue." << endl;
			cout << "Enter 5 to add to both chrisStack and chrisQueue." << endl;
			cout << "Enter 6 to remove from both chrisStack and chrisQueue." << endl;
			cout << "or Enter 0 to quit" << endl;
			cin >> choice;
		}
		if (choice == 0) { exit(EXIT_SUCCESS); }

		switch (choice) {

			case 1:	cout << "Enter an int to add to chrisStack." << endl;
					cin >> anInt;
					chrisStack.add(anInt);
					cout << "Added int " << anInt << " to chrisStack." << endl;
					break;

			case 2: if (!chrisStack.isEmpty()) {
						chrisStack.remove(removedVar1);
						cout << "Removed int " << removedVar1 << " from chrisStack!" << endl;
						}else{ cout << "chrisStack is empty! Removed nothing from chrisStack!" << endl; }
					break;

			case 3:	cout << "Enter an int to add to chrisQueue." << endl;
					cin >> anInt;
					chrisQueue.add(anInt);
					cout << "Added int " << anInt << " to chrisQueue." << endl;
					break;

			case 4:	if (!chrisQueue.isEmpty()) {
						chrisQueue.remove(removedVar2);
						cout << "Removed int " << removedVar2 << " from chrisQueue!" << endl;
						}else{ cout << "chrisQueue is empty! Removed nothing from chrisQueue!" << endl; }
					break;

			case 5:	cout << "Enter an int to add to both chrisStack and ChrisQueue." << endl;
					cin >> anInt;
					chrisStack.add(anInt);
					chrisQueue.add(anInt);
					cout << "Added int " << anInt << " to chrisStack and ChrisQueue." << endl;
					break;

			case 6:	if (!chrisStack.isEmpty()) {
						chrisStack.remove(removedVar1);
						cout << "Removed int " << removedVar1 << " from chrisStack!" << endl;
						}else{ cout << "chrisStack is empty!" << endl << "Removed nothing from chrisStack!" << endl; }
					if (!chrisQueue.isEmpty()) {
						chrisQueue.remove(removedVar2);
						cout << "Removed int " << removedVar2 << " from chrisQueue!" << endl;
						}else{ cout << "chrisQueue is empty!" << endl << "Removed nothing from chrisQueue!" << endl; }
					break;

			cout << "Enter q to quit or any other character to keep adding/removing!" << endl;
			cin >> manControl;
		}
	}
	cout << endl << "Thank you!" << endl;
}