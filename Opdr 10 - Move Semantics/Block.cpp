#include "Block.h"
#include <iostream>

Block::Block(int size, std::string name) : name(name), size(size) {
    std::cout << "CTOR Block '" << name << "' @" << this << std::endl;
    this->data = new int[size];
}

Block::~Block() noexcept {
    std::cout << "DTOR Block '" << this->name << "' @" << this << std::endl;
    delete[] data;
}

Block::Block(const Block& other) : name(other.name), size(other.size) {
    std::cout << "CCTOR Block '" << other.name << "' @" << this << std::endl;
    this->data = new int[size];

    std::copy(other.data, other.data + other.size, data);
}

Block& Block::operator=(const Block& other) {
    std::cout << "Assignment opr Block '" << this->name << "' @" << this << std::endl;
    if (this == &other) return *this;

    delete[] data;

    this->name = other.name;
    this->size = other.size;
    this->data = new int[size];
    std::copy(other.data, other.data + other.size, data);
    return *this;
}


#ifdef MOVESEMANTICS

// move-constructor
Block::Block(Block&& other) noexcept {
    std::cout << "MCTOR from Block '" << other.name << "' @" << &other << " to Block @" << this << std::endl;
    name = std::move(other.name);
    data = other.data;
    size = other.size;
    other.reset();
}

//TODO: move-assignment operator
Block& Block::operator=(Block&& other) noexcept
{
    // TODO: insert return statement here
    std::cout << "Move operator =" << std::endl;
    if (this != &other) {
        name = std::move(other.name);
        data = std::move(other.data);
        size = std::move(other.size);
        other.reset(); // Dit niet aanroepen zorgt voor een exception
    }
    return *this;
}
void Block::reset()
{
    // 'reset' 't originele object
    name = "(nodata: has been moved)";
    size = 0;
    data = nullptr;
}
#endif



std::ostream& operator<<(std::ostream& os, const Block& block) {
    os << "Block @" << &block << " name:" << block.name << " size:" << block.size;
    return os;
}
