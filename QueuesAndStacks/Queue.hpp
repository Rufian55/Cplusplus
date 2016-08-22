/****************************************************************************************
** Program Filename: Queue.hpp
** Author: Chris Kearns (CS-162-400 W2016)
** Date: 2/14/2016
** Description: Queue class declaration file adapted from Gaddis, Chapter 18.
** Input:
** Output:
*****************************************************************************************/
#ifndef QUEUE_HPP
#define QUEUE_HP
#include<cstdlib>

class Queue {
private:
	class QueueNode {								// Data type of the nodes - could be Creature!
		friend class Queue;							// Set to friend so we have access to Queue members.
		int var;									// The var that will be contained by Queue nodes.
		QueueNode *next;							// Declare Queuenode type pointer next.
		// Constructor for the QueueNodes.
		QueueNode(int var1, QueueNode *next1 = NULL) {	// QueueNode pointer next1 = NULL as queue is initialized empty. 
			var = var1;							// Sets the var variable in each new node to var1 paramter.
			next = next1;							// Sets each new node's next pointer to NULL as it's the back
		}										// of the queue where the new QueueNode is being added.
	};
	QueueNode *front;								// QueueNode pointer to keep track of the front of the queue.
	QueueNode *back;								// QueueNode pointer to keep track of the back of the queue.
public:
	Queue();										// Queue class constructor prototype.
	~Queue();										// Queue class destructor prototype.
	
	void add(int);									// Prototype.
	int remove(int &);								// Prototype.
	bool isEmpty();								// Prototype.
	void clear();									// Prototype.
};
#endif // !QUEUE_HPP