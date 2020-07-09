// Opdr 3 - Bankrekening
// Bob Jeltes

#include <iostream>
#include "Bankrekening.h"
#include "Transactie.h"

int main()
{
    Bankrekening rekening = Bankrekening();
    std::cout << "created rekening" << std::endl;
    Transactie transactie = Transactie(5.0f, "vandaag");
    std::cout << "created transaction" << std::endl;
    rekening = rekening + transactie;
    std::cout << "added transaction to rekening" << std::endl;
    // ISSUE: insertion operator causes nullpointer in vector class
    //std::cout << rekening;

    return 0;
}
