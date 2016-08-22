/****************************************************************************************
** Program Filename: Medussa.hpp
** Author: Chris Kearns (CS-162-400 W2016)
** Date: 2/28/2016
** Description: Medussa child class declaration file.
*****************************************************************************************/
#ifndef MEDUSSA_HPP
#define MEDUSA_HPP
#include "Creature.hpp"
#include<string>
using std::string;

class Medusa : public Creature {
private:
	
protected:
	int strength;	// 8
	int numDie_A;	// 2
	int dieSides_A;	// 6
	int numDie_D;	// 1
	int dieSides_D;	// 6
	int armor;		// 3
	int player;
	string name;
	string type;
	int cScore;

public:
	Medusa(string, string, int);
	~Medusa();
	void setStrength(int);
	int getStrength();
	void setDieSides_A(int);
	int getDieSides_A();
	void setNumDie_A(int);
	int getNumDie_A();
	void setDieSides_D(int);
	int getDieSides_D();
	void setNumDie_D(int);
	int getNumDie_D();
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