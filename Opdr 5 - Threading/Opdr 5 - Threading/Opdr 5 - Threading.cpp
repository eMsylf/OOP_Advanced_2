// Opdr 5 - Threading
// Bob Jeltes

#include <iostream>
#include <thread>
#include "ConcurrentVector.h"

//void justJoin(std::thread& _thread);
//void justDetach(std::thread& _thread);
//void joinThenDetach(std::thread& _thread);
//void detachThenJoin(std::thread& _thread);
//void hurpadur();
////void threadExperiment1();
//void threadingExampleEdwin();
//void square(int x);

int exampleNumber = 0;

void square(int x) {
    std::cout << "Hello from thread " << std::this_thread::get_id() << std::endl;
    exampleNumber += x * x;
}

void exampleEdwinThread() {
    ConcurrentVector concVec;
    concVec.AddNumber(exampleNumber); // 0

    std::thread thread(&ConcurrentVector::AddNumber, concVec, exampleNumber);
    concVec.AddNumber(exampleNumber); // 0

    std::thread thread2(&ConcurrentVector::AddNumber, concVec, exampleNumber);
    std::thread thread3(&ConcurrentVector::AddNumber, concVec, exampleNumber);
    thread.detach();
    thread2.join();
    thread3.join();
    concVec.AddNumber(exampleNumber); // 0

    //thread.join();
    concVec.AddNumber(exampleNumber); // both results

    concVec.AddNumber(exampleNumber); // both results
    std::cout << "accum = " << exampleNumber << std::endl;
}

class Task {
public:
    void square(int x) {
        std::cout << "Hello from thread " << std::this_thread::get_id() << std::endl;
        exampleNumber += x * x;
    }
};

void exampleEdwinThreadMemberFunction() {
    Task* taskPtr = new Task();

    std::thread thread(&Task::square, taskPtr, 25);
    //thread.join(); // wait for thread completion
    thread.detach(); // racecondition! cout below reached before thread finishes...

    std::cout << "accum = " << exampleNumber << std::endl;

    delete taskPtr;
}

int main()
{
    exampleEdwinThread();
    exampleEdwinThreadMemberFunction();
    return 0;
}

//void threadingExampleEdwin() {
//    //std::thread anotherThread(&square, 254);
//
//    //anotherThread.join();
//    //anotherThread.detach();
//
//    std::cout << "accum = " << exampleNumber << std::endl;
//}
//
//void square(int x) {
//    std::cout << "Hello from thread" << std::this_thread::get_id() << std::endl;
//    exampleNumber += x * x;
//}
//
//void threadExperiment1() {
//    // How do I do the thing with the threads?
//    std::thread thread1(hurpadur, 25);
//    std::thread thread2;
//
//    std::cout << "Input a number between 0 and 3";
//    int input;
//    std::cin >> input;
//    switch (input)
//    {
//    case 0:
//        justJoin(thread1);
//        break;
//    case 1:
//        justDetach(thread1);
//        break;
//    case 2:
//        joinThenDetach(thread1);
//        break;
//    case 3:
//        detachThenJoin(thread1);
//        break;
//    default:
//        break;
//    }
//}
//
//// Werkt??
//void justJoin(std::thread& _thread) {
//    _thread.join();
//}
//
//// Lijkt niks te doen
//void justDetach(std::thread& _thread) {
//    _thread.detach();
//}
//
//// Geeft error
//void joinThenDetach(std::thread& _thread) {
//    _thread.join();
//    _thread.detach();
//}
//
//// Geeft error
//void detachThenJoin(std::thread& _thread) {
//    _thread.detach();
//    _thread.join();
//}
//
//void hurpadur() {
//
//    std::cout << "Write a thing here" << std::endl;
//}
