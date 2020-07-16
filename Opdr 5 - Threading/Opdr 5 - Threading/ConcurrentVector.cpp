#include "ConcurrentVector.h"

void ConcurrentVector::AddNumber(int number)
{
	vector.push_back(number);
	std::cout << "added " << number << " to list position " << vector.size() << std::endl;
}

void ConcurrentVector::AddNumbers(std::vector<int> numbers)
{
	std::cout << "Start adding numbers";
	for (size_t i = 0; i < numbers.size(); i++)
	{
		vector.push_back(numbers[i]);
	}
}

void ConcurrentVector::DisplayValues()
{
	std::cout << "\n-----------\nDisplay values:\n";
	for (size_t i = 0; i < vector.size(); i++)
	{
		std::cout << "Value " << i << ": " << vector[i] << std::endl;
	}
	std::cout << std::endl;
}
