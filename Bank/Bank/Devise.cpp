#include "Devise.h"

using namespace std;
#include<iostream>


Bank::Devise::Devise(std::string code, double montant):code(code), montant(montant)
{
}

void Bank::Devise::operator+=(const Devise& D)
{
	this->montant += D.montant;
}

bool Bank::Devise::operator==(const Devise& D)
{
	 return (this->code == D.code);
}

std::string Bank::Devise::to_string() const
{
	return std::to_string(this->montant)+" "+this->code;
}

Bank::Devise::~Devise()
{
}
