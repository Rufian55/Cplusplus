/****************************************************************************************
** Program Filename: White.hpp
** Author: Chris Kearns
** Date: 3/13/2016
** Description: White abstract class declaration file.
*****************************************************************************************/
#ifndef WHITE_HPP
#define WHITE_HPP
#include "Space.hpp"
#include <string>
using std::string;

class White : public Space {
private:
	bool mrWhiteVisit;
	bool mrWhiteFood;
	bool mrWhiteDrink;
	bool yetiVisit;
	bool yetiFood;
	bool yetiDrink;
	bool brianVisit;
	bool brianFood;
	bool brianDrink;
	bool stormTrooperVisit;
	bool stormTrooperFood;
	bool stormTrooperDrink;
	bool wilmaVisit;
	bool wilmaFood;
	bool wilmaDrink;

protected:
	Space *W_Blue;
	Space *W_Yellow;
	Space *W_Cyan;
	Space *W_Green;
	Space *W_Red;
	Space *W_Magenta;
	bool pPiece;
	int strength;

public:
	void setWhitePtrs(Space*, Space*, Space*, Space*, Space*, Space*);
	~White();
	void setStrength();
	virtual void setStrength(int);		// Local Overload.
	virtual int getStrength();		// Local strength.
	virtual int acceptStrength(int);	// From Throwback strength.

	void setPPWhite(bool);
	void setPPWhite();			//Overload.
	virtual bool getPPWhite();
	void initCharBools();

	virtual int runRoom();
	virtual void boostStrength();		// Special Pure Virtual Function! 
	int runCharacters();
	int runController(int);
	int playerAI();

	int runMrWhite(int);
	int runYeti(int);
	int runBrian(int);
	int runStormTrooper(int);
	int runWilma(int);

	// White Room Characters
	void setMrWhiteVisit(bool);
	bool getMrWhiteVisit();
	void setMrWhiteFood(bool);
	bool getMrWhiteFood();
	void setMrWhiteDrink(bool);
	bool getMrWhiteDrink();

	void setYetiVisit(bool);
	bool getYetiVisit();
	void setYetiFood(bool);
	bool getYetiFood();
	void setYetiDrink(bool);
	bool getYetiDrink();

	void setBrianVisit(bool);
	bool getBrianVisit();
	void setBrianFood(bool);
	bool getBrianFood();
	void setBrianDrink(bool);
	bool getBrianDrink();

	void setStormTrooperVisit(bool);
	bool getStormTrooperVisit();
	void setStormTrooperFood(bool);
	bool getStormTrooperFood();
	void setStormTrooperDrink(bool);
	bool getStormTrooperDrink();

	void setWilmaVisit(bool);
	bool getWilmaVisit();
	void setWilmaFood(bool);
	bool getWilmaFood();
	void setWilmaDrink(bool);
	bool getWilmaDrink();

	void setBlue(Space*);
	void setYellow(Space*);
	void setCyan(Space*);
	void setGreen(Space*);
	void setRed(Space*);
	void setMagenta(Space*);
};
#endif
