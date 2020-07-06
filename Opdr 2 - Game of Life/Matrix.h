#pragma once
#include <vector>
#include <iostream>
#include "Cel.h"
#include "windows.h"
#include <ctime>
class Matrix
{
public:
	int width = 5;
	int height = 5;
	Cell* cells[50][50];

	Matrix(int _width, int _height);
	int getArea();
	void setGrid();
	int evaluateCell(Cell _cell);
	//bool evaluateCellReproduction(Cell _cell);
	void print();

};

