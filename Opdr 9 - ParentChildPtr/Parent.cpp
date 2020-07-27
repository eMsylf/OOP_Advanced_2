#include <iostream>
#include "Parent.h"

Parent::Parent(std::string name) {
    this->name = name;
    std::string childName = "ChildOf" + name;
    this->child = std::make_unique<Child>(childName);
}

Parent::Parent(const Parent& other) {
    std::cout << "Parent cctor" << std::endl;
    this->name = other.name;
    this->child = std::make_unique<Child>(*other.child);
}

Parent::~Parent() {
    std::cout << "Parent dtor : " << this->name << std::endl;
    //delete this->child;
}

Parent& Parent::operator=(const Parent& other) {
    std::cout << "Parent assignment" << std::endl;

    if (this == &other) return *this;

    this->name = other.name;
    //delete this->child;
    this->child = std::make_unique<Child>(*other.child);

    return *this;
}

Parent::Parent(Parent&& other) noexcept
{
    std::cout << "Movement constructor from parent '" << other.name << "' @" << &other << " to parent @" << this << std::endl;
    name = std::move(other.name);
    child = std::move(other.child);
    other.reset();
}

Parent& Parent::operator=(Parent&& other) noexcept
{
    std::cout << "Move operator =" << std::endl;
    if (this != &other) {
        name = std::move(other.name);
        child = std::move(other.child);
        other.reset();
    }
    return *this;
}

void Parent::reset()
{
    name = "name not set";
    child = nullptr;
}

std::ostream& operator<<(std::ostream& os, const Parent& parent) {
    os << "parent name: " << parent.name << "," << *parent.child;
    return os;
}
