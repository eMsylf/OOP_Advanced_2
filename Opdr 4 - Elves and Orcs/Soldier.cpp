#include "Soldier.h"

Soldier::Soldier(NPC* _npc) : Profession(_npc)
{
}

Soldier::~Soldier()
{
}

void Soldier::render()
{
	Profession::render();
	std::cout << "Soldier" << std::endl;
}
