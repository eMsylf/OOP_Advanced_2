#include "Farmer.h"


Farmer::Farmer(NPC* _npc) : Profession(_npc)
{
}

Farmer::~Farmer()
{
}

void Farmer::render()
{
	Profession::render();
	std::cout << "Farmer" << std::endl;
}
