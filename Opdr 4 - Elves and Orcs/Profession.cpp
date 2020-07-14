#include "Profession.h"

Profession::Profession(NPC* _npc)
{
	theNPC = _npc;
}

Profession::~Profession()
{
	if (theNPC) delete theNPC;
}

void Profession::render()
{
	theNPC->render();
	std::cout << "This NPC is a ";
}
