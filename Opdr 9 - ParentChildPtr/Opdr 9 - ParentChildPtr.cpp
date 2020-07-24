#include <iostream>
#include "Parent.h"

int main() {
    std::shared_ptr<Parent> p1 = std::make_shared<Parent>("Parent1");
    std::cout << "p1: " << *p1 << std::endl;
    //std::cout << "c1: " << *p1->child;


    std::shared_ptr<Parent> p2 = std::make_shared<Parent>(*p1); // roept de copy constructor aan
    std::cout << "p2: " << *p2 << std::endl;
    //std::cout << "c2: " << *p2->child;
    std::shared_ptr<Parent> p3 = std::make_shared<Parent>("Parent3");
    std::cout << "p3: " << *p3 << std::endl;

    *p3 = *p1; // roept de assignment operator aan
    std::cout << "p1:" << *p3 << std::endl;
    
    //Child* c1 = p1->child.get();
    //Child* c2 = p2->child.get();
    //Child* c3 = p3->child.get();

    //delete &p1;
    //delete &p2;
    //delete &p3;

    std::shared_ptr<Parent> p4 = std::make_shared<Parent>(*p3);
    std::cout << "p4: " << *p4 << std::endl;

    return 0;
}