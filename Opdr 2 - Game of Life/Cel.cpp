#include "Cel.h"

Cell::Cell(int xCoord, int yCoord, bool _alive)
{
	x = xCoord;
	y = yCoord;
	alive = _alive;
}

char Cell::getSymbol()
{
	return alive?aliveSymbol:deadSymbol;
}

bool Cell::evaluateNeighbors()
{

	return false;
}

void Cell::live()
{
	alive = true;
	//std::cout << "Cell " << x << ", " << y << " was born\n";
}

void Cell::die()
{
	alive = false;
	//std::cout << "Cell " << x << ", " << y << " died\n";
}
