#pragma once
#include "NPC.h"
class Orc :
	public NPC
{
public:
	Orc(std::string _name);

	void render();
};

