#include "Transactie.h"

//Transactie::Transactie(AfBij _afBij, float _bedrag, std::string _datum)
//{
//	afBij = _afBij;
//	bedrag = _bedrag;
//	datum = _datum;
//}

Transactie::Transactie()
{
}

Transactie::Transactie(float _bedrag, std::string _datum)
{
	if (_bedrag == 0)
		std::cout << "Transaction amount cannot be exactly 0" << std::endl;
	if (_bedrag < 0)
		afBij = AfBij::Af;
	if (_bedrag > 0)
		afBij = AfBij::Bij;
	bedrag = _bedrag;
	datum = _datum;
}
