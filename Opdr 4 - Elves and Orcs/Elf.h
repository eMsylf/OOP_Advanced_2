#pragma once
#include "NPC.h"
class Elf :
	public NPC
{
public:
	Elf(std::string _name);

	void render();
};

