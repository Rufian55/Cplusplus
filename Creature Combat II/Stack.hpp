/****************************************************************************************
** Program Filename: Stack.hpp
** Author: Chris Kearns (CS-162-400 W2016)
** Date: 2/28/2016
** Description: Stack class declaration file for Creature objects.
*****************************************************************************************/
#ifndef STACK_HPP
#define STACK_HPP
#include<cstdlib>
#include "Creature.hpp"

class Stack : Creature {
private:
	class StackNode {											// Data type of the nodes - could be Creature!
	private:
		friend class Stack;										// Set to friend so we have access to Stack members.
		Creature *aCreature;									// a Creature type pointer.
		StackNode *next;										// Declare Stacknode type pointer next.
		// Constructor for the StackNodes.
		StackNode(Creature *aCret, StackNode *next1 = NULL) {	// StackNode pointer next1 = NULL as stack is initialized empty.  
			aCreature = aCret;									// Sets the Creature pointer var in each new node to *aCret paramter.
			next = next1;										// Sets each new node's next pointer to NULL as it's the top.
		}
	};
	StackNode *top;							// Declare a stackNode pointer top used to indicate the top of the stack.
public:
	Stack() { top = NULL; }					// Stack constructor initializes using StackNode pointer top = NULL (empty stack).
	void add(Creature *);					// Prototype.
	bool isEmpty();							// Prototype.
	Creature* remove();						// Prototype.

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
#endif // !STACK_HPP