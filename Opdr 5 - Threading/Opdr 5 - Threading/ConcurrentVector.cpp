#include "ConcurrentVector.h"

void ConcurrentVector::AddNumber(int number)
{
	mutex.lock();
	vector.push_back(number);
	std::cout << "added " << number << " to list position " << vector.size() << std::endl;
	mutex.unlock();
}

void ConcurrentVector::AddNumbers(std::vector<int> numbers)
{
	mutex.lock();
	std::cout << "Start adding numbers";
	for (size_t i = 0; i < numbers.size(); i++)
	{
		vector.push_back(numbers[i]);
	}
	mutex.unlock();
}

void ConcurrentVector::AddManySameNumbers(int amount, int value) {
	mutex.lock();
	for (size_t i = 0; i < amount; i++)
	{
		vector.push_back(value);
	}
	mutex.unlock();
}

void ConcurrentVector::DisplayValues()
{
	mutex.lock();
	std::cout << "\n-----------\nDisplay values:\n";
	std::string output = "";
	for (size_t i = 0; i < vector.size(); i++)
	{
		//std::cout << "Value " << i << ": " << vector[i] << std::endl;
		std::string stringIterator = std::to_string(i);
		output += "Value ";
		output += stringIterator;
		output += "\: ";
		output += std::to_string(vector[i]);
		output += '\n';
	}
	std::cout << output;
	mutex.unlock();
}
