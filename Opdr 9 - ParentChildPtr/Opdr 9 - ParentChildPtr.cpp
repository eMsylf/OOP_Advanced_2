#include <iostream>
#include "Parent.h"

int main() {
    Parent* p1 = new Parent("Parent1");
    std::cout << "p1: " << *p1 << std::endl;
    std::cout << "c1: " << *p1->child;


    Parent* p2 = new Parent(*p1); // roept de copy constructor aan
    std::cout << "p2: " << *p2 << std::endl;
    std::cout << "c2: " << *p2->child;
    Parent* p3 = new Parent("Parent3");
    std::cout << "p3: " << *p3 << std::endl;

    *p3 = *p1; // roept de assignment operator aan
    std::cout << "p1:" << *p3 << std::endl;
    
    Child* c1 = p1->child.get();
    Child* c2 = p2->child.get();
    Child* c3 = p3->child.get();

    delete p1;
    delete p2;
    delete p3;

    return 0;
}