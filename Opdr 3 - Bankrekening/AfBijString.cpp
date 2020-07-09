#include "AfBijString.h"

std::string AfBijString::toString(AfBij value)
{
	switch (value)
	{
	case AfBij::Af:
		return af;
		break;
	case AfBij::Bij:
		return bij;
		break;
	default:
		break;
	}

	return "";
}
