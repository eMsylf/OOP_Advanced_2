#include "Elf.h"

Elf::Elf(std::string _name)
{
	name = _name;
}

void Elf::render()
{
	std::cout << "Render an Elf with the name " + name << std::endl;
}
