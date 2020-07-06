// Opdr 2 - Game of Life.cpp
// Bob Jeltes

#include <iostream>
#include "Matrix.h"

//int cooldown = 3;
bool Start = true;
Matrix matrix = Matrix(20, 20);
bool autoContinue = false;

int main()
{
	if (Start) {
		// Set alive cells
		matrix = Matrix(50, 50);
		matrix.setGrid();
		Start = false;
	}
	else {
		int changes = 0;
		for (size_t i = 0; i < matrix.width; i++)
		{
			for (size_t j = 0; j < matrix.height; j++)
			{
				Cell* cell = matrix.cells[i][j];
				int neighbors = matrix.evaluateCell(*cell);
				if (cell->alive) {
					if (neighbors < 2 || neighbors > 3) {
						cell->die();
						changes++;
					}
				}
				else {
					if (neighbors == 3) {
						cell->live();
						changes++;
					}
				}
			}
		}
		if (changes == 0) {
			std::cout << "No changes occurred. The system is stable. Exiting.";
			return 1;
		}
	}

	matrix.print();

	if (autoContinue) {
		main();
		return 1;
	}
	bool validInput = false;
	while (!validInput) {
		char input;
		std::cout << "Press [a] to continue, press [q] to quit. Input [A] to enable auto-continue.";
		std::cin >> input;
		if (input == 'a') {
			main();
			return 2;
		}
		else if (input == 'A') {
			autoContinue = true;
			main();
			return 3;
		}
		else if (input == 'q') {
			return 4;
		}
	}
}

