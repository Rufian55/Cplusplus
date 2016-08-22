/****************************************************************************************
** Program Filename: Stack.cpp
** Author: Chris Kearns
** Date: 2/14/2016
** Description: Stack class implementation file.
** Input:
** Output:
*****************************************************************************************/
#include "Stack.hpp"
#include<iostream>
using std::cout;
using std::endl;


/***************************************************************************************
** Function: add();
** Description: Adds a new node with int num as the var onto the top of the stack with
** the *top pointer pointed at it.  See StackNode constructor definition in Stack.hpp.
** Parameters: int.
** Pre-Conditions:
** Post-Conditions:
****************************************************************************************/
void Stack::add(int num) {
	top = new StackNode(num, top);
}


/***************************************************************************************
** Function: remove()
** Description: Removes the top node from the stack and the var in that node from the
** top of the stack. Note the temp stackNode type pointer used to facillitate the  
** removal in order to keep the pointers pointed correctly and delete the removed nodes 
** pointer.
** Parameters: reference num - used to save the node's var being removed from the stack. 
** Pre-Conditions:
** Post-Conditions:
****************************************************************************************/
int Stack::remove(int &num) {

	StackNode *temp;					// Declare StackNode type pointer.

	if (isEmpty()) {
		cout << "The stack is empty!" << endl << endl;
	}else{							// Remove value off top of stack.
		num = top->var;					// num is set to the removed var via pointer.
		temp = top;					// temp-orarily assign as the top pointer.
		top = top->next;				// Assign top the "next" pointer.
		delete temp;					// Delete the temp (just removed pointer).
	}
}

/***************************************************************************************
** Function: isEmpty()
** Description: Checks if the stack is empty by checking to see if top has been set to 
** NULL. Returns true if so, false if not.
** Parameters: none.
** Pre-Conditions:
** Post-Conditions:
****************************************************************************************/
bool Stack::isEmpty() {
	if (!top) {						// is top pointer set to NULL?
		return true;
	}else{
		return false;
	}
}
