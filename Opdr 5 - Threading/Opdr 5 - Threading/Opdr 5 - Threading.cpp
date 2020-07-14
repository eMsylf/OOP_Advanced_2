// Opdr 5 - Threading
// Bob Jeltes

#include <iostream>
#include <thread>

void justJoin(std::thread& _thread);
void justDetach(std::thread& _thread);
void joinThenDetach(std::thread& _thread);
void detachThenJoin(std::thread& _thread);
void hurpadur();

int main()
{
    std::cout << "Hello World!\n";


    // How do I do the thing with the threads?
    std::thread thread(hurpadur);

    justJoin(thread);
    //justDetach(thread);
    //joinThenDetach(thread);
    //detachThenJoin(thread);
}

// Geeft GEEN errors?????
void justJoin(std::thread& _thread) {
    _thread.join();
}

// Lijkt niks te doen
void justDetach(std::thread& _thread) {
    _thread.detach();
}

// Geeft error
void joinThenDetach(std::thread& _thread) {
    _thread.join();
    _thread.detach();
}

// Geeft error
void detachThenJoin(std::thread& _thread) {
    _thread.detach();
    _thread.join();
}

void hurpadur() {
    std::cout << "Write a thing here" << std::endl;
}
