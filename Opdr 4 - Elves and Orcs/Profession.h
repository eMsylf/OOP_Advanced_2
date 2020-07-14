#pragma once
#include <iostream>
#include "NPC.h"

class Profession : public NPC
{
private:
	NPC* theNPC;
public :
	Profession(NPC* _npc);
	virtual ~Profession();

	virtual void render();
};
