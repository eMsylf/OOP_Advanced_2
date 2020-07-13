// Opdr 4 - Elves and Orcs
// Bob Jeltes

#include <iostream>
#include "Elf.h"
#include "Orc.h"
int main()
{
    Elf elf = Elf("hurpadur");
    Orc orc = Orc("aaaaaaay");
    std::cout << elf.name << std::endl;
    std::cout << orc.name << std::endl;



    std::cout << "Type something and press enter!\n";
    std::string a;
    std::cin >> a;


    std::cout << "You typed: " << a;
}
