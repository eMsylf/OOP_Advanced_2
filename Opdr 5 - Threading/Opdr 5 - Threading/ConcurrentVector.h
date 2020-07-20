#pragma once
#include <vector>
#include <iostream>
#include <thread>
#include <chrono>
#include <thread>
#include <mutex>
class ConcurrentVector
{
public:
	std::mutex mutex;
	std::vector<int> vector;

	void AddNumber(int number);
	void AddNumbers(std::vector<int> numbers);
	void AddManySameNumbers(int amount, int value);

	void DisplayValues();
};

