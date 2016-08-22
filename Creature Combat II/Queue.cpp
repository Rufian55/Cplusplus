/****************************************************************************************
** Program Filename: Queue.cpp
** Author: Chris Kearns
** Date: 2/28/2016
** Description: Queue class implementation file.
*****************************************************************************************/
#include "Queue.hpp"
#include<iostream>
using std::cout;
using std::endl;


Queue::Queue(){		// Queue constructor setting front and back pointers to NULL
	front = NULL;
	back = NULL;
}

Queue::~Queue(){	// Queue destructor that calls clear() function to remove all nodes.
	clear();
}

/***************************************************************************************
** Function: add();
** Description: Adds a node to the queue and aligns pointers correctly.
** Parameters: Creature pointer that is to be added to the queue.
** Pre-Conditions: An instantiation of a Creature queue in driver program.
** Post-Conditions: A Creature pointer is added to the queue.
****************************************************************************************/
void Queue::add(Creature *aCreature){
	if (isEmpty()) {				// Checks if the queue is empty.
		front = new QueueNode(aCreature);	// front pointer assigned the new QueueNode with aCreature pointer as var.
		back = front;				// back pointer now points to front - just one node!
	}else{
		back->next = new QueueNode(aCreature);	// back pointer gets the new QueueNode object pointer.
		back = back->next;			// back pointer now points to the new QueueNode. 
	}
}


/***************************************************************************************
** Function: remove()
** Description: Removes a node from the queue and copies it into num.
** Parameters: Creature pointer to be removed.
** Pre-Conditions: The creature pointer is in the queue.
** Post-Conditions: Creature pointer is removed.
****************************************************************************************/
Creature* Queue::remove() {
	QueueNode *temp;				// Declare QueueNode type pointer.
	if (isEmpty()) {
		cout << "The queue is empty!" << endl;
	}
	else {						// Remove value from the front of the queue.
		Creature* Cret = front->aCreature;	// Cret is set to the removed var via pointer.
		temp = front;				// temp-orarily assign as the front pointer.
		front = front->next;			// Assign front the "next" pointer.
		delete temp;				// Delete the temp (just removed pointer).
		return Cret;
	}
}


/***************************************************************************************
** Function: isEmpty()
** Description: Checks if the queue is empty and returns true if so, false if not.
** Parameters: none.
** Pre-Conditions:
** Post-Conditions:
****************************************************************************************/
bool Queue::isEmpty() {
	if (front == NULL) {				// is top pointer set to NULL?
		return true;
	}else{
		return false;
	}
}


/***************************************************************************************
** Function: clear()
** Description: "dequeues" (removes) all the elements in the queue.
** Parameters: none.
** Pre-Conditions:
** Post-Conditions:
****************************************************************************************/
void Queue::clear(){
	Creature *rCreature;				// A pointer for remove() operation when
	while (!isEmpty()) {				// called by Destructor.
		remove();
	}
}
