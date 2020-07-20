// Opdr 5 - Threading
// Bob Jeltes

#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <ctime>
#include <chrono>
#include "ConcurrentVector.h"
//#include "ThreadsTutorial.h"
//#include "ConcurrentVector.h"

int exampleNumber = 0;
//std::mutex mutex;

void square(int x) {
    std::cout << "Squaring from thread " << std::this_thread::get_id() << std::endl;
    exampleNumber += x * x;
}

void calculate() {
    std::vector<std::thread> threads;
    for (int i = 0; i <= 100; i++)
    {
        threads.push_back(std::thread(&square, i));
    }

    for (std::thread& thread : threads)
    {
        thread.join();
    }
    std::cout << "Total = " << exampleNumber << std::endl;
}



int main()
{
    /*for (int i = 0; i < 3; i++)
    {
        exampleNumber = 0;
        calculate();
    }*/
    ConcurrentVector* concVector = new ConcurrentVector();
    for (int i = 0; i < 100; i++)
    {
        std::thread th1(&ConcurrentVector::AddNumber, concVector, 1);
        th1.detach();
    }
    for (int i = 0; i < 100; i++)
    {
        std::thread th2(&ConcurrentVector::AddNumber, concVector, 2);
        th2.detach();
    }

    concVector->DisplayValues();
    return 0;
}
