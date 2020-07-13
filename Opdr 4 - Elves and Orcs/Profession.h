#pragma once
#include <string>
class Profession
{
public :
	virtual void render() = 0;
};

class Farmer : public Profession{
	void render();
};

class Soldier {

};

class Shaman {

};


