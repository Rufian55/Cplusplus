/****************************************************************************************
** Program Filename: Blue.hpp
** Author: Chris Kearns
** Date: 3/13/2016
** Description: Blue abstract class declaration file.
*****************************************************************************************/
#ifndef BLUE_HPP
#define BLUE_HPP
#include "Space.hpp"

class Blue : public Space {
private:
	bool sullyVisit;
	bool sullyFood;
	bool sullyDrink;
	bool clawsVisit;
	bool clawsFood;
	bool clawsDrink;
	bool naviVisit;
	bool naviFood;
	bool naviDrink;
	bool cookieMonsterVisit;
	bool cookieMonsterFood;
	bool cookieMonsterDrink;
	bool bobBlobVisit;
	bool bobBlobFood;
	bool bobBlobDrink;

protected:
	Space *B_Yellow;
	Space *B_Cyan;
	Space *B_Green;
	Space *B_Red;
	Space *B_Magenta;
	Space *B_White;
	bool pPiece;
	int strength;

public:
	void setBluePtrs(Space*, Space*, Space*, Space*, Space*, Space*);
	~Blue();
	void setStrength();
	virtual void setStrength(int);		// Local Overload.
	virtual int getStrength();		// Local strength.
	virtual int acceptStrength(int);	// From Throwback strength.

	void setPPBlue(bool);
	void setPPBlue();			//Overload.
	virtual bool getPPBlue();
	void initCharBools();

	virtual int runRoom();
	virtual void boostStrength();		// Special Pure Virtual Function! 
	int runCharacters();
	int runController(int);
	int playerAI();

	// Blue Room Characters
	int runSully(int);
	int runClaws(int);
	int runNavi(int);
	int runCookieMonster(int);
	int runBobBlob(int);

	void setSullyVisit(bool);
	bool getSullyVisit();
	void setSullyFood(bool);
	bool getSullyFood();
	void setSullyDrink(bool);
	bool getSullyDrink();

	void setClawsVisit(bool);
	bool getClawsVisit();
	void setClawsFood(bool);
	bool getClawsFood();
	void setClawsDrink(bool);
	bool getClawsDrink();

	void setNaviVisit(bool);
	bool getNaviVisit();
	void setNaviFood(bool);
	bool getNaviFood();
	void setNaviDrink(bool);
	bool getNaviDrink();

	void setCookieMonsterVisit(bool);
	bool getCookieMonsterVisit();
	void setCookieMonsterFood(bool);
	bool getCookieMonsterFood();
	void setCookieMonsterDrink(bool);
	bool getCookieMonsterDrink();

	void setBobBlobVisit(bool);
	bool getBobBlobVisit();
	void setBobBlobFood(bool);
	bool getBobBlobFood();
	void setBobBlobDrink(bool);
	bool getBobBlobDrink();

	void setYellow(Space*);
	void setCyan(Space*);
	void setGreen(Space*);
	void setRed(Space*);
	void setMagenta(Space*);
	void setWhite(Space*);
};
#endif
