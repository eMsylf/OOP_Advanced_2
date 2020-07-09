#pragma once
#include <iostream>
#include <vector>
#include "Transactie.h"
#include "AfBijString.h"

class Bankrekening
{
public:
	Bankrekening();
	Bankrekening(float _saldo, std::vector<Transactie>* _transactions);

	float saldo;
	std::vector<Transactie>* transactions = {};

	Bankrekening operator+ (const Transactie& transaction) const;
	Bankrekening operator- (const Transactie& transaction) const;
	Bankrekening& operator+= (const Transactie& transaction);

	Bankrekening& operator= (const Bankrekening& bankrekening);
	friend std::ostream& operator << (std::ostream& out, const Bankrekening& bankrekening);
	friend std::istream& operator >> (std::ostream& in, Bankrekening& bankrekening);
};

