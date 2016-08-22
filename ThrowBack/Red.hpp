/****************************************************************************************
** Program Filename: Red.hpp
** Author: Chris Kearns (CS-162-400 W2016)
** Date: 3/13/2016
** Description: Red abstract class declaration file.
*****************************************************************************************/
#ifndef  RED_HPP
#define RED_HPP
#include "Space.hpp"
#include <string>
using std::string;

class Red : public Space {
private:
	bool jeffFungusVisit;
	bool jeffFungusFood;
	bool jeffFungusDrink;
	bool blinkeyVisit;
	bool blinkeyFood;
	bool blinkeyDrink;
	bool redElmoVisit;
	bool redElmoFood;
	bool redElmoDrink;
	bool yosemiteSamVisit;
	bool yosemiteSamFood;
	bool yosemiteSamDrink;
	bool chefVisit;
	bool chefFood;
	bool chefDrink;

protected:
	Space *R_Blue;
	Space *R_Yellow;
	Space *R_Cyan;
	Space *R_Green;
	Space *R_Magenta;
	Space *R_White;
	bool pPiece;
	int strength;

public:
	void setRedPtrs(Space*, Space*, Space*, Space*, Space*, Space*);
	~Red();
	void setStrength();
	virtual void setStrength(int);		// Local Overload.
	virtual int getStrength();			// Local strength.
	virtual int acceptStrength(int);	// From Throwback strength.

	void setPPRed(bool);
	void setPPRed();					//Overload.
	virtual bool getPPRed();
	void initCharBools();

	virtual int runRoom();
	virtual void boostStrength();		// Special Pure Virtual Function! 
	int runCharacters();
	int runController(int);
	int playerAI();

	int runJeffFungus(int);
	int runBlinkey(int);
	int runRedElmo(int);
	int runYosemiteSam(int);
	int runChef(int);

	// Red Room Characters
	void setJeffFungusVisit(bool);
	bool getJeffFungusVisit();
	void setJeffFungusFood(bool);
	bool getJeffFungusFood();
	void setJeffFungusDrink(bool);
	bool getJeffFungusDrink();

	void setBlinkeyVisit(bool);
	bool getBlinkeyVisit();
	void setBlinkeyFood(bool);
	bool getBlinkeyFood();
	void setBlinkeyDrink(bool);
	bool getBlinkeyDrink();

	void setRedElmoVisit(bool);
	bool getRedElmoVisit();
	void setRedElmoFood(bool);
	bool getRedElmoFood();
	void setRedElmoDrink(bool);
	bool getRedElmoDrink();

	void setYosemiteSamVisit(bool);
	bool getYosemiteSamVisit();
	void setYosemiteSamFood(bool);
	bool getYosemiteSamFood();
	void setYosemiteSamDrink(bool);
	bool getYosemiteSamDrink();

	void setChefVisit(bool);
	bool getChefVisit();
	void setChefFood(bool);
	bool getChefFood();
	void setChefDrink(bool);
	bool getChefDrink();

	void setBlue(Space*);
	void setYellow(Space*);
	void setCyan(Space*);
	void setGreen(Space*);
	void setMagenta(Space*);
	void setWhite(Space*);
};
#endif