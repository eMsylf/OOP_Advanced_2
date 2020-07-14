#pragma once
#include "Profession.h"
class Shaman :
	public Profession
{
public:
	Shaman(NPC* _npc);
	virtual ~Shaman();

	void render();
};

