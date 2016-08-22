/****************************************************************************************
** Program Filename: Queue.hpp
** Author: Chris Kearns
** Date: 2/28/2016
** Description: Queue class declaration file for a doubly linked circular linked list.
** Input:
** Output:
*****************************************************************************************/
#ifndef QUEUE_HPP
#define QUEUE_HPP
#include<cstdio>
#include<cstdlib>

class Queue {
	struct QueueNode {					// Struct QueueNode for the Queue
		int data;
		struct QueueNode *next;
		struct QueueNode *prev;

	};
	QueueNode *front;					// Front pointer for controlling the Queue.
	QueueNode *back;					// Back pointer for controlling the Queue.
public:
	Queue();
	~Queue();
	QueueNode *makeNode(int);
	void addBack(int);
	int getFront();
	int removeFront();
	void showList();
};
#endif // !QUEUE_HPP
