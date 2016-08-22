/****************************************************************************************
** Program Filename: Main.cpp
** Author: Chris Kearns
** Date: 3/06/2016
** Description: STL Stack and STL Queue class demonstration file that initializes and
** manipulates a stack used as a palindrome string generator and a buffer queue with 
** randomly generated values that are added and removed based on user defined probabilty.
** Input: user run program.
** Output: cout to console.
*****************************************************************************************/
#include "Stack.hpp"
#include "Queue.hpp"
#include "chrisLib.hpp"
#include <algorithm>
using std::transform;
#include <cstdlib>
#include<ctime>
#include<string>
using std::string;
#include<iostream>
using std::cin;
using std::cout;
#include<iomanip>
using std::setprecision;
#include<queue>
using std::queue;


int main() {
	srand(time(0));
	double pctPut;
	double pctRem;
	int iters;
	double i;
	Queue my;
	queue<int> chrisQueue;
	string sControl = "y";
	string qControl = "y";
	int cueLen = 0;


	// Menu system loop.
	while (qControl == "y" || qControl == "Y") {
		//User input collection menu
		pctPut = bufHeader();
		pctRem = remHeader();
		iters = itersHeader();

		// Logic for adding and removing to/from the buffer.
		for (i = 0; i < iters; i++) {
			if(my.isTrue(pctPut))
				chrisQueue.push(my.intGen());
			else if (my.isTrue(pctRem)) {
				if (chrisQueue.empty() == false)
					chrisQueue.pop();	
			}
		cueLen = cueLen + chrisQueue.size();
		cout << "The Avg. Length of the buffer for iteration " << i+1 << " was: " 
			<< setprecision(4) << cueLen/(i+1) << "\n";
		}
		cueLen = 0;

		// Continue with Buffer Demo?
		cout << "\nTry the Buffer Demo again? Enter \"y\" for yes, or any other char to see\n"
			<< "the Palindrome Demo\n";
		cin >> qControl;
		cin.clear();
		cin.ignore(256, '\n');

		// Yes or No, we empty the buffer queue THEN loop up or move on to the Palindrome Demo.
		while (chrisQueue.empty() == false) {
			chrisQueue.pop();
		}
	}

	// Palindrome Stack Demo.
	int var;
	string pControl = "y";
	string palin;
	Stack stk;

	while (pControl == "y" || pControl == "Y") {
		// Menu header - User determines palindrome case.
		var = checkVar();// 1, 2, 3, or 4.
		if (var == 4) { exit(1); }
		// Convert string per User input
		palin = caser(var);
		// Process the string and cout the palindrome.
		cout << stk.palinBuilder(palin) << "\n";

		cout << "Enter \"y\" to convert another string, any other char to quit.\n";
		cin >> pControl;
		cin.clear();
		cin.ignore(256, '\n');
		if (pControl != "y" && pControl != "Y") {
			cout << "Thanks for watching the Demos\n";
			exit(1);
		}
	}
}
