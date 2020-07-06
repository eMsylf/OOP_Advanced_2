#include "Matrix.h"

Matrix::Matrix(int _width, int _height)
{
	width = _width;
	height = _height;
	std::cout << "Created grid with width " << width << " and height " << height << "\n";
	for (size_t i = 0; i < width; i++)
	{
		for (size_t j = 0; j < height; j++)
		{
			cells[i][j] = new Cell(i, j, false);
		}
	}
	//grid = { width, height };
}

int Matrix::getArea()
{
	return width * height;
}

void Matrix::setGrid()
{
	bool randomizeCells = false;
	std::srand(time(NULL));
	for (size_t i = 0; i < width; i++)
	{
		for (size_t j = 0; j < height; j++)
		{
			if (randomizeCells) {

				int value = round(((double)std::rand() / (RAND_MAX)));
				//std::cout << "Value: " << value;
				value?cells[i][j]->live():cells[i][j]->die();
				continue;
			}
			std::cout << "Cell " << i << ", " << j << ": \nA for Alive \nD for Dead \nL to skip to next line\nR to Randomize all left-over cells\nE to Escape and skip all remaining cells.\n";

			char input;
			std::cin >> input;
			if (input == 'A') {
				cells[i][j]->live();
			}
			else if (input == 'D') {
				cells[i][j]->die();
			}
			else if (input == 'R') {
				randomizeCells = true;
				std::cout << "Randomizing cells...\n";
			}
			else if (input == 'E')
				return;
			else if (input == 'L') {
				j = height;
			}
			else {
				std::cout << "Invalid input.";
				j--;
			}
		}
	}
}

int Matrix::evaluateCell(Cell _cell)
{
	int x = _cell.x;
	int y = _cell.y;
	//std::cout << "Check cell with coordinates " << x << ", " << y;
	int neighborsAlive = 0;
	if (x != 0) {
		// Check left
		if (cells[x - 1][y]->alive)
			neighborsAlive++;
	}
	if (x != width -1) {
		// Check right
		if (cells[x + 1][y]->alive)
			neighborsAlive++;
	}
	if (y != 0) {
		// Check up
		if (cells[x][y - 1]->alive)
			neighborsAlive++;
	}
	if (y != height -1) {
		// Check down
		if (cells[x][y + 1]->alive)
			neighborsAlive++;
	}
	
	return neighborsAlive;
}

//bool Matrix::evaluateCellReproduction(Cell _cell) {
//	if ()
//}

void Matrix::print()
{
	std::string output;
	output += "0000000000000000000000000000000000000000000000\n";
	for (size_t i = 0; i < width; i++)
	{
		for (size_t j = 0; j < height; j++)
		{
			output += cells[i][j]->getSymbol();
		}
		output += '\n';
	}
	output += "0000000000000000000000000000000000000000000000\n";
	//system("CLS");
	std::cout << output;
	Sleep(500);
	std::cout << std::flush;
}
