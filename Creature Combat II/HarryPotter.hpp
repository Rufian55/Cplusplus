/****************************************************************************************
** Program Filename: HarryPotter.hpp
** Author: Chris Kearns
** Date: 2/28/2016
** Description: HarryPotter child class declaration file.
*****************************************************************************************/
#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP
#include "Creature.hpp"
#include<string>
using std::string;

class HarryPotter : public Creature {
private:

protected:
	int strength;	// 10
	int numDie;	//  2
	int dieSides;	//  6
	int armor;	//  0
	int deadOnce;	//  0
	int player;
	string name;
	string type;
	int cScore;

public:
	HarryPotter(string, string, int);
	~HarryPotter();
	void setStrength(int);
	int getStrength();
	void setDieSides(int);
	int getDieSides();
	void setNumDie(int);
	int getNumDie();
	void setArmor(int);
	int getArmor();
	void setPlayer(int);
	int getPlayer();
	void setName(string);
	string getName();
	void setDeadOnce(int);
	int getDeadOnce();
	void hogWarts();
	int roll(string);
	int attack();
	void defend(int);
	bool checkPulse();
	void healer();
	void setType(string);
	string getType();
	void setcScore(int);
	int getcScore();
};
#endif
