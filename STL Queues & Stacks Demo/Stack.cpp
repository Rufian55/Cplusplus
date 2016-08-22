/********************************************************************************
** Program Filename: Stack.cpp
** Author: Chris Kearns
** Date: 3/06/2016
** Description: STL Stack class implementation file.
** Input:
** Output:
*********************************************************************************/
#include "Stack.hpp"
#include<stack>
using std::stack;


/*******************************************************************************
**			function isPalin()
** Accepts string parameter and compares itself to a reveresed string using the
** string libaray public memeber reverse iterators rbegin and rend.  Returns true
** if reveresed string == input string, indicating input was already a palindrome.
** // h ttp://www.cplusplus.com/reference/string/string/rbegin/
** // h ttp://www.cplusplus.com/reference/string/string/rend/
******************************************************************************/
bool Stack::isPalin(string palin){
	if (palin == string(palin.rbegin(), palin.rend())) {
		return true;
	} else {
		return false;
	}
}


/*******************************************************************************
**			function palinBuilder()
** Accepts string parameter, calls isPalin for the case of input already being
** a palindrome and returns it. Otherwise, the input string is added to an stl
** type char stack character by character, and then conveniently removed LIFO
** to be appended to the back of the input string to constuct and return the
** palindrome.
******************************************************************************/
string Stack::palinBuilder(string palin){
	if (isPalin(palin)) {
		return palin;
	} else {
		int i = 0;
		int len = palin.length();
		stack<char> chrisStack;
		while (i < len) {
			chrisStack.push(palin.at(i));
			i++;
		}
		while (chrisStack.empty() == false) {
			char poped = chrisStack.top();
			palin = palin + poped;
			chrisStack.pop();
		}
		return palin;
	}
}
