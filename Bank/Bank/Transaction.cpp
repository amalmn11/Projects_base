#include "Transaction.h"
using namespace std;
#include<iostream>

Bank::Transaction::Transaction(string type, Devise* montant, string):type(type), montant(montant), date(date)
{
	
}

void Bank::Transaction::affichertransaction() const
{
	cout << "l'operation de " << this->type << " " << this->montant->to_string() << " on " << this->date << endl;
}

Bank::Transaction::~Transaction()
{
}
