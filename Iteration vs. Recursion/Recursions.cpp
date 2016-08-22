#include "Recursions.hpp"
#include <iostream>
using std::cin;
using std::cout;

/************************************************************************
*		rfactorial() Non Tail Recursive (From Lab 10 Specs)				*
*************************************************************************/
long long Recursions::rfactorial(int n) {
	if (n == 1)
		return 1;
	else
		return n * rfactorial(n - 1);
}


/************************************************************************
*		factorial() Tail Recursive (From Lab 10 Specs)					*
*************************************************************************/
long long Recursions::factorial(int n) {
	return factorialHelper(n, 1);
}


/************************************************************************
*		Tail Recursion Helper Function (From Lab 10 Specs)				*
*************************************************************************/
long long Recursions::factorialHelper(int n, int result) {
	if (n == 1)
		return result;
	else
		return factorialHelper(n - 1, n*result);
}

/************************************************************************
*			User choice collection Function collect_1()					*
*************************************************************************/
int Recursions::collect_1(int low, int high) {
	int choice;
	cout << "Enter an int 'n' from " << low << " to " << high << " to see"
		<< " recursive and non recursive\nmethod for returning the 'nth'"
		<< "Fibonacci sequence number\n";
	while (!(cin >> choice) || choice < low || choice > high) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "\nInput Error! Enter an int > " << low << " and <= "
			<< high << "!\n";
	}
	return choice;
}

/************************************************************************
*			User choice collection Function collect_2()					*
*************************************************************************/
int Recursions::collect_2(int low, int high) {
	int choice;
	cout << "\nEnter an int 'n' from " << low << " to " << high
		<< " to see Non Tail Recursive and Tail Recursive\nmethod for "
		<< "returning the 'nth' Factorial number\n";
	while (!(cin >> choice) || choice < low || choice > high) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "\nInput Error! Enter an int > " << low << " and <= "
			<<  high << "!\n";
	}
	return choice;
}