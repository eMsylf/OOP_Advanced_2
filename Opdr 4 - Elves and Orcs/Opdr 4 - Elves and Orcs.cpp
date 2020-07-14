// Opdr 4 - Elves and Orcs
// Bob Jeltes

#include <iostream>
#include "Elf.h"
#include "Orc.h"
#include "Farmer.h"

int main()
{
    Elf* elf = new Elf("hurpadur");
    Orc* orc = new Orc("aaaaaaay");

    elf->render();
    orc->render();

    std::cout << "Type something and press enter!\n";
    std::string a;
    std::cin >> a;


    std::cout << "You typed: " << a;
}
