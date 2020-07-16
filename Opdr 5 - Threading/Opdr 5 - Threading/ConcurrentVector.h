#pragma once
#include <vector>
#include <iostream>
#include <mutex>
class ConcurrentVector
{
public:
	std::vector<int> vector;
	//std::mutex mutex;

	void AddNumber(int number);
	void DisplayValues();
};

