/****************************************************************************************
** Program Filename: Queue.cpp
** Author: Chris Kearns (CS-162-400 W2016)
** Date: 2/14/2016
** Description: Queue class implementation file.
** Input:
** Output:
*****************************************************************************************/
#include "Queue.hpp"
#include<iostream>
using std::cin;
using std::cout;
using std::endl;


Queue::Queue(){			// Queue constructor setting front and back pointers to NULL
	front = NULL;
	back = NULL;
}

Queue::~Queue(){		// Queue destructor that calls clear() function to remove all nodes.
	clear();
}

/***************************************************************************************
** Function: add();
** Description: Adds a node to the queue and aligns pointers correctly.
**
** Parameters: int num that is to be added to the queue.
** Pre-Conditions:
** Post-Conditions:
****************************************************************************************/
void Queue::add(int num){
	if (isEmpty()) {					// Checks if the queue is empty.
		front = new QueueNode(num);		// front pointer assigned the new QueueNode with num var.
		back = front;					// back pointer now points to front - just one node!
	}else{
		back->next = new QueueNode(num);// back pointer gets the new QueueNode object.
		back = back->next;				// back pointer now points to the new QueueNode. 
	}
}


/***************************************************************************************
** Function: remove()
** Description: Removes a node from the queue and copies it into num.
**
** Parameters: reference to num.
** Pre-Conditions:
** Post-Conditions:
****************************************************************************************/
int Queue::remove(int &num) {
	QueueNode *temp;									// Declare QueueNode type pointer.
	if (isEmpty()) {
		cout << "The queue is empty!" << endl;
	}else{											// Remove value from the front of the queue.
		num = front->var;								// num is set to the removed var via pointer.
		temp = front;									// temp-orarily assign as the front pointer.
		front = front->next;							// Assign front the "next" pointer.
		delete temp;									// Delete the temp (just removed pointer).
	}
}


/***************************************************************************************
** Function: isEmpty()
** Description: Checks if the queue is empty and returns true if so, false if not.
**
** Parameters: none.
** Pre-Conditions:
** Post-Conditions:
****************************************************************************************/
bool Queue::isEmpty() {
	if (front == NULL) {								// is top pointer set to NULL?
		return true;
	}else{
		return false;
	}
}


/***************************************************************************************
** Function: clear()
** Description: "dequeues" (removes) all the elements in the queue.
**
** Parameters: none.
** Pre-Conditions:
** Post-Conditions:
****************************************************************************************/
void Queue::clear(){
	int aVar;									// A var for remove() operation when
	while (!isEmpty()) {						//   called by Destructor.
		remove(aVar);
	}
}