#pragma once
#include <string>
#include "AfBij.h"
class AfBijString
{
public:
	std::string toString(AfBij value);
private:
	std::string af = "af";
	std::string bij = "bij";
};

