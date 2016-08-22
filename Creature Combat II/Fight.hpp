/****************************************************************************************
** Program Filename: Fight.hpp
** Author: Chris Kearns
** Date: 2/28/2016
** Description: Fight class declaration file.
** Input:
** Output:
*****************************************************************************************/
#ifndef FIGHT_HPP
#define FIGHT_HPP
#include "Creature.hpp"
#include<string>
using std::string;

class Fight : public Creature {
private:
protected:
public:
	Fight() {};
	~Fight() {};
	void creatureSort(Creature* array[], int);

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
