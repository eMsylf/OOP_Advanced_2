#pragma once
#include <iostream>

class Cell
{
public:
	int x;
	int y;
	const char deadSymbol = ' ';
	const char aliveSymbol = '-';
	bool alive;

	Cell(int xCoord, int yCoord, bool _alive);
	char getSymbol();
	bool evaluateNeighbors();
	void live();
	void die();
};

