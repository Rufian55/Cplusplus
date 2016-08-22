/****************************************************************************************
** Program Filename: ThrowBack.hpp
** Author: Chris Kearns (CS-162-400 W2016)
** Date: 3/13/2016
** Description: ThrowBack abstract class declaration file.
*****************************************************************************************/
#ifndef THROWBACK_HPP
#define THROWBACK_HPP
#include "Space.hpp"

class ThrowBack : Space {
private:
	int strength;
	bool ppBlue;
	bool blueWinFlag;
	bool ppYellow;
	bool yellowWinFlag;
	bool ppCyan;
	bool cyanWinFlag;
	bool ppGreen;
	bool greenWinFlag;
	bool ppRed;
	bool redWinFlag;
	bool ppMagenta;
	bool magentaWinFlag;
	bool ppWhite;
	bool whiteWinFlag;
	int win;
	int gameTime;
	int unixTime;
	int suppress;
protected:
	char backPack[7];					// Container, limit 7 chars.
public:
	ThrowBack() {
		initBP();
		setStrength();
		setWin();
		initPPieces();
		setSuppress(false);
	}
	~ThrowBack() {}						// Memory management handled by throwBack()

	void throwBack(Space*, Space*, Space*, Space*, Space*, Space*, Space*, Space*, ThrowBack*);

	void setStrength() { this->strength = 50; }		// Local initializer.
	virtual void setStrength(int);				// Overload local setter.
	virtual int getStrength();				// Local getter.

	void initBP();
	void displayBP();
	void updateBP();
	void setWin() { this->win = 0; }			// Local initiakizer.
	void setWin(int);					// Overload.
	int getWin();
	void initPPieces();
	void setGameTime();
	int getGameTime();
	int getUnixTime();
	bool checkTime();
	void setSuppress(bool);
	bool getSuppress();

	void setPPBlue(bool);
	bool getPPBlue();
	void setPPYellow(bool);
	bool getPPYellow();
	void setPPCyan(bool);
	bool getPPCyan();
	void setPPRed(bool);
	bool getPPRed();
	void setPPGreen(bool);
	bool getPPGreen();
	void setPPMagenta(bool);
	bool getPPMagenta();
	void setPPWhite(bool);
	bool getPPWhite();

	virtual void boostStrength() {}				// "Special" virtual function!
};
#endif
