#include <iostream>
#include "Parent.h"

void printParent(Parent& parent) {
    std::cout << "Parent info: "
        << parent
        << std::endl
        /*<< "Parent use count: "
        << parent.use_count()
        << std::endl*/
        << "------------"
        << std::endl;
}

int main() {
    std::shared_ptr<Parent> p1 = std::make_shared<Parent>("Parent1");
    std::cout << "p1: " << *p1 << std::endl;

    std::shared_ptr<Parent> p2 = std::make_shared<Parent>(*p1); // roept de copy constructor aan
    std::cout << "p2: " << *p2 << std::endl;

    std::shared_ptr<Parent> p3 = std::make_shared<Parent>("Parent3");
    std::cout << "p3: " << *p3 << std::endl;

    *p3 = *p1; // roept de assignment operator aan
    std::cout << "p3:" << *p3 << std::endl;

    // Stap 2.2
    std::cout << "Parent 3 use count: "<< p3.use_count() << std::endl;
    std::shared_ptr<Parent> p4 = p3; // Shared pointer p3 wordt nu 2 keer gebruikt i.p.v. 1 keer
    std::cout << "p4: " << *p4 << std::endl;
    std::cout << "Parent 3 use count: "<< p3.use_count() << std::endl;

    std::cout << "==== Child names of all parents: ====" << std::endl;
    std::cout << *p1->child << std::endl;
    std::cout << *p2->child << std::endl;
    std::cout << *p3->child << std::endl;
    std::cout << *p4->child << std::endl;
    std::cout << "--------" << std::endl;;
    p1->child.reset();
    std::cout << "--------" << std::endl;;
    std::cout << "==== Child names of all parents except p1: ====" << std::endl;
    std::cout << *p2 << std::endl;
    std::cout << *p3 << std::endl;
    std::cout << *p4 << std::endl;

    // OPDR 10
    std::cout << "Opdracht 10" << std::endl;
    *p3 = std::move(*p4); // Move operator wordt hierbij aangeroepen

    printParent(*p3); // Move operator wordt hier ook bij aangeroepen
    std::cout << "=======END OF MAIN=======" << std::endl;
    return 0;
}