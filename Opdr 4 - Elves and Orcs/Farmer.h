#pragma once
#include "Profession.h"
class Farmer :
	public Profession
{
public:
	Farmer(NPC* _npc);
	virtual ~Farmer();

	void render();
};

