/****************************************************************************************
** Program Filename: Stack.hpp
** Author: Chris Kearns (CS-162-400 W2016)
** Date: 2/14/2016
** Description: Stack class declaration file.
** Input:
** Output:
*****************************************************************************************/
#ifndef STACK_HPP
#define STACK_HPP
#include<cstdlib>

class Stack {
private:
	class StackNode {									// Data type of the nodes - could be Creature!
		friend class Stack;								// Set to friend so we have access to Stack members.
		int var;										// The var that will be contained by Stack nodes.
		StackNode *next;								// Declare Stacknode type pointer next.
		// Constructor for the StackNodes.
		StackNode(int var1, StackNode *next1 = NULL) {		// StackNode pointer next1 = NULL as stack is initialized empty.  
			var = var1;								// Sets the var variable in each new node to var1 paramter.
			next = next1;								// Sets each new node's next pointer to NULL as it's the top.
		}

	};
	StackNode *top;									// Declare a stackNode pointer top used to indicate the top of the stack.
public:
	Stack() { top = NULL; }								// Stack constructor initializes using StackNode pointer top = NULL (empty stack).
	void add(int);										// Prototype.
	int remove(int &);									// Prototype.
	bool isEmpty();									// Prototype.
};
#endif // !STACK_HPP