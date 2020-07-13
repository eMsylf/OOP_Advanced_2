#include "Bankrekening.h"

Bankrekening::Bankrekening()
{
	std::cout << "Create bankrekening";
	saldo = 0;
	transactions = new std::vector<Transactie>;
}

Bankrekening::Bankrekening(float _saldo, std::vector<Transactie>* _transactions)
{
	saldo = _saldo;
	transactions = _transactions;
}

Bankrekening Bankrekening::operator+(const Transactie& transaction) const
{
	std::cout << "+ Operator start" << std::endl;
	Transactie* newTransaction = new Transactie(transaction.bedrag, transaction.datum);
	transactions->push_back(*newTransaction);
	std::cout << "+ Operator end" << std::endl;
	return Bankrekening(saldo + newTransaction->bedrag, transactions);
}

Bankrekening Bankrekening::operator-(const Transactie& transaction) const
{
	transactions->push_back(transaction);
	return Bankrekening(saldo - transaction.bedrag, transactions);	
}

Bankrekening& Bankrekening::operator+=(const Transactie& transaction)
{
	saldo += transaction.bedrag;
	transactions->push_back(transaction);
	return *this;
}

Bankrekening& Bankrekening::operator=(const Bankrekening& bankrekening)
{
	std::cout << "Equals operator start" << std::endl;
	if (this != &bankrekening) {
		//std::cout << "assignment: " << std::endl;
		this->saldo = bankrekening.saldo;
		this->transactions = bankrekening.transactions;
	}
	std::cout << "Equals operator end" << std::endl;
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Bankrekening& bankrekening)
{
	std::cout << "Insertion operator start" << std::endl;
	//out << "Balance before transaction: " << bankrekening.saldo << std::endl;
	AfBijString converter;
	if (bankrekening.transactions == nullptr) {
		std::cout << "Null pointer!" << std::endl;
		return out;
	}
	out << "Banksaldo: " << bankrekening.saldo << std::endl;
	out << "Transacties: " << std::endl;
	for (size_t i = 0; i < bankrekening.transactions->size(); i++)
	{
		Transactie transaction = bankrekening.transactions->at(i);
		
		out 
			<< "Transactie: "
			<< converter.toString(transaction.afBij) 
			<< ": " 
			<< transaction.bedrag 
			<< " Euro. Datum: " 
			<< transaction.datum
			<< std::endl
			;
	}
	std::cout << "Insertion operator end" << std::endl;

	return out;
}
