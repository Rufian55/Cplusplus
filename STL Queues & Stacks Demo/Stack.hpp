/****************************************************************************************
** Program Filename: Stack.hpp
** Author: Chris Kearns (CS-162-400 W2016)
** Date: 3/06/2016
** Description: STL Stack class declaration file.
** Input:
** Output:
*****************************************************************************************/
#ifndef STACK_HPP
#define STACK_HPP
#include<string>
using std::string;

class Stack {
public:
	bool isPalin(string);
	string palinBuilder(string);
};
#endif // !STACK_HPP