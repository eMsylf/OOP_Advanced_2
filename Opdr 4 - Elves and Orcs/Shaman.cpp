#include "Shaman.h"

Shaman::Shaman(NPC* _npc) : Profession(_npc)
{
}

Shaman::~Shaman()
{
}

void Shaman::render()
{
	Profession::render();
	std::cout << "Shaman" << std::endl;
}
