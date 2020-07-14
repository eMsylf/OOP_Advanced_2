#pragma once
#include "Profession.h"
class Soldier :
	public Profession
{
public:
	Soldier(NPC* _npc);
	virtual ~Soldier();

	void render();
};

