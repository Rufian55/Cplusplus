/****************************************************************************************
** Program Filename: Recursion.cpp
** Author: Chris Kearns (CS-162-400 W2016)
** Date: 1/31/2016
** Description: Recursion class implementation file.
** Input: User input for the three Recursion class funtions to operate.
** Output: cout to the console, depending on the individual function, a string or an int.
*****************************************************************************************/
#include "Recursion.hpp"
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
#include<string>


/***************************************************************************************
** Function: revString(string);
** Description: Recursion class function that reverses a string with recursion. Each
** recursion drops first char of remaining string with substr call parameter of 1 
** (the second char in the string) and appends the previously captured char_0 character
** to the result string. Each return is the char_0 only.  Recursion halts when string
** length of 0 is encountered in substr call.
** Parameters: input string str2bRev as input by user.
** Pre-Conditions: Runs on Linux console.
** Post-Conditions: cout the reversed string char by char. '\n' added in main()
****************************************************************************************/
string Recursion::revString(string str2bRev) {
	// First, if string length is 0 or 1, skip recursion block.
	if (str2bRev.size() > 1) {

		// Obtain the first char for each recursion.
		char char_0 = str2bRev.at(0);

		// Determine input string size.
		int strSize = str2bRev.size();

		// Recursive call on substring with char[0] "skipped" and char_0 appended
		// to the back of the return string. Only char_0 gets returned each recursion.
		string result = revString(str2bRev.substr(1, strSize)) + char_0;

		return result;
	}
	else {
		//Base case, string length of 0 or 1.
		return str2bRev;
	}
}


/***************************************************************************************
** Function: sumArray(int[], int);
** Description: Recursion class function that sums the array elements.
** Parameters: an array of ints, an int represeting the number of elements in the array.
** Pre-Conditions: Runs on Linux console.
** Post-Conditions: Returns the summed value.
****************************************************************************************/
int Recursion::sumArray(int anArray[], int len) {
	
	// Base case, array length = 0, so 0 is returned.
	if (len == 0) {
		return 0;
	}
	else {
		// Base case of array size = 1, therefore, anArray[0] value is returned.
		if (len == 1) {
			return anArray[0];
		}
		else {
			// Var result set to value of last element.
			int result = anArray[len - 1];
			// Add each element to result, len decrements by 1 each recursion call.
			return result + sumArray(anArray, len - 1);
		}
	}
}


/***************************************************************************************
** Function: triNum(int);
** Description: Calculates the triangle number for the input int, similar to a bowling
** pin triangle. So, int n = 5 would return 5+4+3+2+1, but does so recurseively with the
** recursive call (s - 1) parameter. 
** Parameters: int n
** Pre-Conditions: an int.
** Post-Conditions: returns an int representing the above.
****************************************************************************************/
int Recursion::triNum(int i){
	// Base case int = 0
	if (i == 0) {
		return 0;
	}
	// Base case int = 1
	else {
		if (i == 1) {
			return 1;
		}
		// Recursive case.
		else {
			return i + triNum(i - 1);
		}
	}
}


int main() {
	int choice = 0;		// Main menu flow control var.
	string aString;		// Local user input collector string.
	int numInts;		// Local user input for number of ints to enter for sumArray();
	int newInt;			// Indivdual ints entered by user for sumArray();
	int count;			// Counter for input to sumArray();
	int anInt;			// Local user input collector for Triangle Number for triNum();
	Recursion cursion;	// Initialize a Recursion object.

	// Main menu.
	cout << endl << "Welcome to Lab 4: Recursion" << endl;
	while(choice != 4){
		cout << endl
			<< "Enter 1 to run revString() (Returns your entered string reversed)." << endl
			<< "Enter 2 to run sumArray() (Sums your array's elements)." << endl
			<< "Enter 3 to run triNum() (Returns the Triangle Number of your int)." << endl
			<< "Enter 4 to quit." << endl;
		cin.clear();
		cin >> choice;
		// Input validation.
		while (cin.fail() || choice < 1 || choice > 4) {
			cout << endl << "Error!" << endl
				<< "Enter 1 to run revString() (Returns your entered string reversed)." << endl
				<< "Enter 2 to run sumArray() (Sums your array's elements)." << endl
				<< "Enter 3 to run triNum(); (Returns the Triangle Number of your int)." << endl
				<< "Enter 4 to quit." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cin >> choice;
		}

		// User has chosen 1, function revString().
		if (choice == 1) {
			cout << "Please enter your string to be reversed." << endl;
			cin.ignore(256, '\n');
			getline(cin, aString);
			// Function revString() call.
			cout << endl << "Your string reversed is: " << cursion.revString(aString) + '\n';
		}
		else {

			//User has chosen 2, function sumArray();
			if (choice == 2) {
				cout << "Please enter an int for the number of elements to enter into your array." << endl;
				cin.clear();
				cin >> numInts;
				// Input validation.
				while (cin.fail() || numInts < 1 || numInts > 100) {
					cout << endl << "Error!" << endl
						 << "Please enter an int for the number of elements to enter into your array." << endl
						 << "The range the program will accept is an int from 1 to 100." << endl;
					cin.clear();
					cin.ignore(256, '\n');
					cin >> numInts;
				}

				// Declare static array of 100 elements.
				int anArray[100];				
				count = 0;
				for (int i = 0; i < numInts; i++) {
					cout << "Please enter int # " << i+1 << " and press <Enter>" << endl;
					cin >> newInt;
					while (cin.fail()) {
						cout << endl << "Error!" << endl
							 << "Please enter only an int for int # " << i+1 << " and press <Enter>" << endl;
						cin.clear();
						cin.ignore(256, '\n');
						cin >> newInt;
					}
					anArray[i] = newInt;
					count++;
				}

				// ...and finally, the call to sumArray();
				cout << "The sum of the your array's elements = " << cursion.sumArray(anArray, count) << endl;
			}
			else {

				// User has chosen 3, function triNum();
				if (choice == 3) {
					// Erroneous output and/or segmentation fault for int values > approximately 150,000. 
					cout << "Please enter an int > 0 you would like to know the Trianngle Number" << endl
						 << "for or 0 to return to the menu. Entering 0 will also print the" << endl
						 << "Trianlge Number for 0. Upper limit is 100,000." << endl;
					cin >> anInt;
					// Input validation.
					while (cin.fail() || anInt < 0 || anInt > 100000) {
						cout << "Error! Enter an int from 1 to 100,000." << endl;
						cin.clear();
						cin.ignore(256, '\n');
						cin >> anInt;
					}
					cout << endl << "The Triangle Number for " << anInt << " = " << cursion.triNum(anInt) << endl;
				}
			}
		}
	}// End Main Menu while loop.

	 // End Program selected.
	if (choice == 4)
		return 0;
}