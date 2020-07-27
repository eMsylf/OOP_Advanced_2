#pragma once

#include <string>
#include <ostream>
#include "Child.h"

class Parent {
public:
    Parent(std::string name);
    Parent(const Parent& other);
    virtual ~Parent();
    Parent& operator=(const Parent& other);
    
    // OPDR 10 - MOVE OPERATOR & CONSTRUCTOR
    Parent(Parent&& other) noexcept;
    Parent& operator=(Parent&& other) noexcept;

    void reset();

    friend std::ostream& operator<<(std::ostream& os, const Parent& parent);

    std::unique_ptr<Child> child;
private:
    std::string name;
};

