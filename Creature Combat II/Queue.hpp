/****************************************************************************************
** Program Filename: Queue.hpp
** Author: Chris Kearns
** Date: 2/28/2016
** Description: Queue class declaration file.
*****************************************************************************************/
#ifndef QUEUE_HPP
#define QUEUE_HP
#include<cstdlib>
#include "Creature.hpp"

class Queue : Creature {
private:
	class QueueNode {						// Data type of the nodes.
	private:
		friend class Queue;					// Set to friend so we have access to Queue members.
		Creature *aCreature;					// a Creature type pointer.
		QueueNode *next;					// Declare Queuenode type pointer next.
		// Constructor for the QueueNodes.
		QueueNode(Creature *aCret, QueueNode *next1 = NULL) {	// QueueNode pointer next1 = NULL as queue is initialized empty. 
			aCreature = aCret;				// Sets the Creature pointer var in each new node to *aCret paramter.
			next = next1;					// Sets each new node's next pointer to NULL as it's the back
		}							// of the queue where the new QueueNode is being added.
	};
	QueueNode *front;						// QueueNode pointer to keep track of the front of the queue.
	QueueNode *back;						// QueueNode pointer to keep track of the back of the queue.
public:
	Queue();
	~Queue();
	
	void add(Creature *);
	Creature* remove();
	bool isEmpty();
	void clear();

	// Virtual function placeholders.
	int roll(string) {};
	int attack() {};
	void defend(int) {};
	bool checkPulse() {};
	int getStrength() {};
	int getPlayer() {};
	string getName() {};
	string getType() {};
	void healer() {};
	void setcScore(int) {};
	int getcScore() {};
};
#endif
