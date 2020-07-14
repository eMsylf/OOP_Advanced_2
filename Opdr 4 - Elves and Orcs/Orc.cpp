#include "Orc.h"

Orc::Orc(std::string _name)
{
	name = _name;
}

void Orc::render()
{
	std::cout << "Render an Orc with the name " + name << std::endl;
}
