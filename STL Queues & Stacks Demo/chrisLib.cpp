/*******************************************************************************
**							chrisLib()
** Collection of utility and user input validation functions. #include to your
** main.cpp file and adjust funtions as nesscessry for proper operation.
******************************************************************************/
#include "chrisLib.hpp"
#include "Stack.hpp"
#include<iostream>
using std::cout;
using std::cin;
#include <algorithm>
using std::transform;
#include<string>
using std::string;
#include<stack>


/*******************************************************************************
**							function bufHeader()
** User collection function for determining desired probability of adding a 
** randomly generated value to the buffer (chrsiQueue). Returns the collected
** pctPut double to be used for stl queue functions.
** Input: user.
** Output: pctPut var.
******************************************************************************/
double bufHeader() {
	double pctPut;
	cout << "\nBuffer Simulation Demo.\n"
		<< "Please enter a number from 0 to 100 representing the chance a randomly\n"
		<< "generated value is PUT in the buffer.\n";
	cin >> pctPut;
	cin.clear();
	cin.ignore(256, '\n');
	while (!cin || pctPut < 0 || pctPut > 100) {
		cout << "Input Error!\n"
			<< "Please enter a number from 0 to 100 representing the chance a randomly\n"
			<< "generated value is PUT in the buffer.\n";
		cin >> pctPut;
		cin.clear();
		cin.ignore(256, '\n');
	}
	return pctPut;
}


/*******************************************************************************
**							function remHeader()
** User input collection function for determining desired probability of removing
** a value AND the node from the buffer (chrsiQueue). Returns the collected
** pctRem var to be used for stl queue processing
** Input: user.
** Output: pctRem var.
******************************************************************************/
double remHeader() {
	double pctRem;
	cout << "Please enter a number from 0 to 100 representing the chance a value\n"
		<< "is POPed from the buffer.\n";
	cin >> pctRem;
	cin.clear();
	cin.ignore(256, '\n');
	while (!cin || pctRem < 0 || pctRem > 100) {
		cout << "Input Error!\n"
			<< "Please enter a number from 0 to 100 representing the chance a value\n"
			<< "is POPed from the buffer.\n";
		cin >> pctRem;
		cin.clear();
		cin.ignore(256, '\n');
	}
	return pctRem;
}


/*******************************************************************************
**							function itersHeader()
** User input collection function for collecting the number of iterations to run 
** the buffer queue demonsttation program.  Include full user input validation
** and error resolution.
** Input: user.
** Output: iters var.
******************************************************************************/
int itersHeader() {
	int iters;
	cout << "How many iterations of the simulaton would you like to perform?\n"
		<< "The average queue length is returned each turn. Range is 1 to 100.\n";
	cin >> iters;
	cin.clear();
	cin.ignore(256, '\n');
	while (!cin || iters < 0 || iters > 100) {
		cout << "Input Error!\n"
			<< "How many iterations of the simulaton would you like to perform before\n"
			<< "the average queue length is returned? Range is 1 to 100.\n";
		cin >> iters;
		cin.clear();
		cin.ignore(256, '\n');
	}
	return iters;
}


/*******************************************************************************
**							function checkVar()
** User input collection and validation function.  Returns apprpriate var for
** determining behaviour of the palindrome() & ultimately Stack::palinBuilder()
** funtion.
** Input: user.
** Output: int var.
******************************************************************************/
int checkVar() {
	int var;
	cout << "\nPalindrome Builder.\n"
		<< "Enter:\n"
		<< "1. For returning all letters as lowercase.\n"
		<< "2. For returning all letters as uppercase.\n"
		<< "3. For don't change my case! (This will treat, for example,\n"
		<< "\t\"a\" and \"A\" as seperate letters.)\n"
		<< "4. To quit.\n";
	cin >> var;
	cin.clear();
	cin.ignore(256, '\n');
	while (!cin || var < 1 || var > 4) {
		cout << "Input error! Enter:\n"
			<< "1. For returning all letters as lowercase.\n"
			<< "2. For returning all letters as uppercase.\n"
			<< "3. For don't change my case! (This will treat, for example,\n"
			<< "\t\"a\" and \"A\" as seperate letters.)\n"
			<< "4. To quit.\n";
		cin >> var;
		cin.clear();
		cin.ignore(256, '\n');
	}
	return var;
}


/*******************************************************************************
**							function caser()
** User string to be converted to a palindrome collection function that accepts
** an int var == to 1 or 2, ignored otherwise, & sets the user string to upper
** or lower case or allows the mixed upper or lower case string through to
** function Stack::palinbBuilder().
** Input: int var.
** Output: returns input string processed for case per user input.
******************************************************************************/
string caser(int var) {
	string palin;
	cout << "Enter the string you want to be converted to a palindrome.\n";
	cin >> palin;
	cin.clear();
	cin.ignore(256, '\n');
	if (var == 1)
		transform(palin.begin(), palin.end(), palin.begin(), ::tolower);//(1)
	else if (var == 2)
		transform(palin.begin(), palin.end(), palin.begin(), ::toupper);//(1)
	return palin;
}
/*
(1) These transform string to lower/upper case calls adapted from article found
at h ttps://notfaq.wordpress.com/2007/08/04/cc-convert-string-to-upperlower-case/
*/