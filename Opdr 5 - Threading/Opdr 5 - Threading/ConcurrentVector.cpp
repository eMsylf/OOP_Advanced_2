#include "ConcurrentVector.h"

void ConcurrentVector::AddNumber(int number)
{
	std::cout << "Thread " << std::this_thread::get_id() << " started" << std::endl;
	while (busy) {
		std::cout << "Another thread is busy. Trying again in one second: "<< std::this_thread::get_id() << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	busy = true;
	std::cout << "Thread " << std::this_thread::get_id() << " is now busy" << std::endl;
	vector.push_back(number);
	std::cout << "added " << number << " to list position " << vector.size() << std::endl;
	busy = false;
	std::cout << "Thread " << std::this_thread::get_id() << " is now finished" << std::endl;
}

void ConcurrentVector::DisplayValues()
{
	std::cout << "\n-----------\nDisplay values:\n";
	for (size_t i = 0; i < vector.size(); i++)
	{
		/*output += "Value ";
		output += i;
		output += " ";
		output += vector[i];
		output += '\n';*/
		std::cout << "Value " << i << ": " << vector[i] << std::endl;
	}
	/*std::cout << output;*/
	std::cout << std::endl;
}
