#pragma once
#include <vector>
#include <iostream>
#include <thread>
#include <chrono>
class ConcurrentVector
{
public:
	std::vector<int> vector;

	void AddNumber(int number);
	void DisplayValues();
};

