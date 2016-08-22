/****************************************************************************************
** Program Filename: Queue.cpp
** Author: Chris Kearns (CS-162-400 W2016)
** Date: 2/28/2016
** Description: Queue class implementation file for a circular doubly linked linked list
** that recylecs empty nodes from the front to the back.
*****************************************************************************************/
#include "Queue.hpp"
#include<cstdio>
#include<cstdlib>
#include<iostream>
using std::cin;
using std::cout;
using std::endl;


/***************************************************************************************
** Function: Queue() constructor
** Description:	Initiatlizes the Queue and instatniates one node with data = -1 (empty
** sentinal), QueueNode pointers front & back simply point to temp, prev & next are set
** to point at tmp as well but this is done by makeNode().
** Parameters: None.
** Pre-Conditions: Runs on Linux console.
** Post-Conditions:
****************************************************************************************/
Queue::Queue(){
	QueueNode *head = makeNode(-1);
	front = head;
	back = head;
}


Queue::~Queue() {}


/***************************************************************************************
** Function: makeNode()
** Description:	Utility function for createing a stand alone empty node with prev and
** next pointers pointing to itself (temp), front and back also point to it wehn called
** by the Queue constructor.
** Parameters: data int. Returns a QueueNode pointer to itself.
** Pre-Conditions: Runs on Linux console.
** Post-Conditions:
****************************************************************************************/
Queue::QueueNode* Queue::makeNode(int data) {
	struct QueueNode *aNode;
	aNode = new(struct QueueNode);
	aNode->data = data;
	aNode->next = aNode;
	aNode->prev = aNode;
	return aNode;
}


/***************************************************************************************
** Function: addBack(int data)
** Description: Adds data to the back of the queue if empty. If not empty, checks the
** front QueueNode to see if it's empty, if so, recycles it to the back and assigns data
** to it.  If front QueueNode is also full, a new node is added to the back of the Queue
** and data assigned to it.
** Parameters: int data from user.
** Pre-Conditions: Runs on Linux console.
** Post-Conditions: New QueueNode if conditions above are met.
****************************************************************************************/
void Queue::addBack(int data) {
	if (front == back && back->data == -1) {		// back is empty so get on the queue!
		back->data = data;
	}
	else if (front == back && back->data != -1) {	// Queue has 1 node, and it's full so
		struct QueueNode * aNode;				// we add a new node and passing data
		aNode = makeNode(data);					// to it, adjusting pointers to retain
		aNode->next = front;					// circular doubly linked list.
		front->prev = aNode;
		back = aNode;
		front->next = back;
		back->prev = front;
	}
	else if (front != back && back->data == -1) {	// More than one node, but back is empty.
		back->data = data;
	}
	else if (front != back && back->data != 1) {		// More than one node, back is full, so
		if (getFront() == -1) {					// we check if there is an empty one
			front = front->prev;				// on the front and recycle it if so!
			back = back->prev;
			back->data = data;
		}
		else {								// We have >1 node, back & front are full,
			struct QueueNode * aNode;			// so we add a node and assign data to it
			aNode = makeNode(data);				// and adjust pointers to retain the 
			aNode->next = back;					// circularly doubly linked list.
			back->prev = aNode;
			back = aNode;
			front->next = back;
			back->prev = front;
		}
	}
}


/***************************************************************************************
** Function: getFront()
** Description: Returns the value of the data var in the front QueueNode, -1 sentinal
** if empty.
** Parameters: none.
** Pre-Conditions: Runs on Linux console.
** Post-Conditions: Does not mutate.
****************************************************************************************/
int Queue::getFront(){
	return front->data;
}


/***************************************************************************************
** Function: removeFront()
** Description: Removes the data value from the front QueueNode. Returns -1 sentianl if
** the front QueueNode was empty, set's front QueueNode data to -1 if occupied.
** Parameters:
** Pre-Conditions: Runs on Linux console.
** Post-Conditions: Data value in front node == -1.
****************************************************************************************/
int Queue::removeFront() {
	if (front->data == -1) {
		return -1;
	} else if (front->data != -1) {
		front->data = -1;
	}
}
	

/***************************************************************************************
** Function: showList()
** Description: Displays the Queue's QueueNode's data contents in front to back manner.
** Will display the QueueNode in proper order as the Queue is "rotated".
** Parameters:
** Pre-Conditions: Runs on Linux console.
** Post-Conditions:
****************************************************************************************/
void Queue::showList() {
	cout << "The queue, from front to back:\n\n";
	QueueNode * seeker;
	seeker = front;

	if (front == back) {
		cout << "There is one node and it contains: " << seeker->data << "\n";
	}
	else if (front != back) {
		cout << "The \"front\" Node contains: " << seeker->data << "\n";
		do {
			seeker = seeker->prev;
			cout << "Node->prev to this Node contains: " << seeker->data << "\n";
		} while (seeker != back);
	}
}