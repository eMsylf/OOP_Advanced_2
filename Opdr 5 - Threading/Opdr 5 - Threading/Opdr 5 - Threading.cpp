// Opdr 5 - Threading
// Bob Jeltes

#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <ctime>
#include <chrono>
#include "ConcurrentVector.h"

int exampleNumber = 0;

void square(int x) {
    std::cout << "Squaring from thread " << std::this_thread::get_id() << std::endl;
    exampleNumber += x * x;
}

int main()
{
    ConcurrentVector* concVector = new ConcurrentVector();
    for (int i = 0; i < 5; i++)
    {
        std::thread th1(&ConcurrentVector::AddManySameNumbers, concVector, 1000, 1);
        th1.detach();
    }

    for (int i = 0; i < 5; i++)
    {
        std::thread th2(&ConcurrentVector::AddManySameNumbers, concVector, 1000, 2);
        th2.detach();
    }
    
    std::thread outputThread(&ConcurrentVector::DisplayValues, concVector);
    outputThread.join();
    return 0;
}
