// Opdr 5 - Threading
// Bob Jeltes

#include <iostream>
#include <thread>
#include <mutex>
#include "ConcurrentVector.h"

int exampleNumber = 0;
std::mutex mutex;

void square(int x) {
    std::cout << "Squaring from thread " << std::this_thread::get_id() << std::endl;
    exampleNumber += x * x;
}

void pointerVersion() {
    ConcurrentVector* concVec = new ConcurrentVector();
    std::lock_guard<std::mutex> ayylmao(mutex);

    concVec->DisplayValues();
    std::thread thread(&ConcurrentVector::AddNumber, concVec, exampleNumber);
    square(10);
    std::thread thread2(&ConcurrentVector::AddNumber, concVec, exampleNumber);
    square(10);
    //std::thread thread3(&ConcurrentVector::AddNumber, concVec, exampleNumber);
    thread.join();
    thread2.join();
    //thread3.join();
    concVec->DisplayValues();
}

int main()
{
    pointerVersion();
    return 0;
}
