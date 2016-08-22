#include "Space.hpp"
#include "Blue.hpp"
#include "Yellow.hpp"
#include "Cyan.hpp"
#include "Green.hpp"
#include "Red.hpp"
#include "Magenta.hpp"
#include "White.hpp"
#include "ThrowBack.hpp"
#include "GrandPrize.hpp"

int main() {

	// Instatantiate all Rooms/Pointers.
	Space * Player;
	Blue *blue = new Blue;
	Yellow *yellow = new Yellow;
	Cyan *cyan = new Cyan;
	Green *green = new Green;
	Red *red = new Red;
	Magenta *magenta = new Magenta;
	White *white = new White;
	ThrowBack *tBack = new ThrowBack;

	// Set all Room pointers to all other Rooms.
	blue->setBluePtrs(yellow, cyan, green, red, magenta, white);
	yellow->setYellowPtrs(blue, cyan, green, red, magenta, white);
	cyan->setCyanPtrs(blue, yellow, green, red, magenta, white);
	green->setGreenPtrs(blue, yellow, cyan, red, magenta, white);
	red->setRedPtrs(blue, yellow, cyan, green, magenta, white);
	magenta->setMagentaPtrs(blue, yellow, cyan, green, red, white);
	white->setWhitePtrs(blue, yellow, cyan, green, red, magenta);

	//Run Game!!
	tBack->throwBack(blue, yellow, cyan, green, red, magenta, white, Player, tBack);
}