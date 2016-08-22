/****************************************************************************************
** Program Filename: Barbarian.hpp
** Author: Chris Kearns (CS-162-400 W2016)
** Date: 2/28/2016
** Description: Barbarian child class declaration file.
*****************************************************************************************/
#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP
#include "Creature.hpp"
#include<string>
using std::string;

class Barbarian : public Creature {
private:

protected:
	int strength;	// 12
	int numDie;		//  2
	int dieSides;	//  6
	int armor;		//  0
	int player;
	string name;
	string type;
	int cScore;

public:
	Barbarian(string, string, int);
	~Barbarian();
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