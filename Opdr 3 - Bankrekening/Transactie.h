#pragma once
#include <Windows.h>
#include <string>
#include <iostream>
#include "AfBij.h"
class Transactie
{
public:
	AfBij afBij = AfBij::Af;
	float bedrag = 0;
	std::string datum;
	Transactie();
	Transactie(float _bedrag, std::string _datum);

	
};
