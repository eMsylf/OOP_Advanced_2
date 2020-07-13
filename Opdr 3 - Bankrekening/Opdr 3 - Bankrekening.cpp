// Opdr 3 - Bankrekening
// Bob Jeltes

#include <iostream>
#include "Bankrekening.h"
#include "Transactie.h"

int main()
{
    Bankrekening rekening = Bankrekening();
    //std::cout << "created rekening" << std::endl;
    Transactie* transactie = new Transactie(5.0f, "vandaag");
    Transactie* transactie2 = new Transactie(100.f, "gisteren");

    //std::cout << "created transactions" << std::endl;
    rekening += *transactie;
    rekening = rekening - *transactie2;
    //std::cout << "added transaction to rekening" << std::endl;
    // ISSUE: insertion operator causes nullpointer in vector class
    std::cout << rekening << std::endl;

    return 0;
}
