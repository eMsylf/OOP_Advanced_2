#include "ConcurrentVector.h"
#include <iostream>

void ConcurrentVector::AddNumber(int number)
{
	vector.push_back(number);
	std::cout << "added " << number << "to list position " << vector.size() << std::endl;
}
