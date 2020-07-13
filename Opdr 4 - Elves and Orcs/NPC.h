#pragma once
#include <iostream>

class NPC
{
public:
	std::string name;
	
	virtual void render() = 0;
};

