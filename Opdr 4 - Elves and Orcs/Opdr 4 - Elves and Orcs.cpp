// Opdr 4 - Elves and Orcs
// Bob Jeltes

#include <iostream>
#include "Elf.h"
#include "Orc.h"
#include "Farmer.h"
#include "Shaman.h"
#include "Soldier.h"
#include <vector>

int main()
{
    std::vector<NPC*> npcs;

    NPC* regularElf = new Elf("Dylran");
    npcs.push_back(regularElf);

    NPC* farmerElf = new Farmer(new Elf("Threndolyn"));
    npcs.push_back(farmerElf);

    NPC* allRoundOrc = new Farmer(new Shaman(new Soldier(new Orc("Brumpft"))));
    npcs.push_back(allRoundOrc);

    //Elf* elf = new Elf("hurpadur");
    //Orc* orc = new Orc("aaaaaaay");

    regularElf->render();
    farmerElf->render();
    allRoundOrc->render();

    std::cout << "Type something and press enter!\n";
    std::string a;
    std::cin >> a;
    std::cout << "You typed: " << a;

    delete regularElf;
    delete farmerElf;
}
