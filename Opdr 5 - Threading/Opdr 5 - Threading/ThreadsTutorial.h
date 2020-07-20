#pragma once
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>
#define _CRT_SECURE_NO_WARNINGS

class ThreadsTutorial
{
public:
	int GetRandom(int max);

	void ExecuteThread(int id);

};

