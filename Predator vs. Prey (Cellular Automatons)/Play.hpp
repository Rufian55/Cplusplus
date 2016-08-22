/****************************************************************************************
** Program Filename: Play.hpp
** Author: Chris Kearns (CS-162-400 W2016)
** Date: 2/7/2016
** Description: Play class declaration file. 
*****************************************************************************************/
#ifndef PLAY_HPP
#define PLAY_HPP
#include "Critter.hpp"
#include <string>
using std::string;

class Play {
private:
	int row;
	int col;
public:
	Play() {}
	void grid();
	void setRow(int);
	int getRow();
	void setCol(int);
	int getCol();
	int getRandRow();
	int getRandCol();
	string cursorMover();
	void antBreed(int, int);
	void dBugBreed(int, int);
	string palette(int);
};
#endif //!PLAY_HPP