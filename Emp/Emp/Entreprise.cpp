#include "Entreprise.h"

int Entreprise::compteur = 0;

bool Entreprise::ajouterEmployee(Employee* E)
{
	if (this->capacity == this->nbEmp)
	{
		this->resize();
	}
	this->emp[this->nbEmp++] = E;


}

Entreprise::Entreprise(string, string)
{
}

void Entreprise::afficherall() const
{

}

void Entreprise::resize()
{
	this->capacity *= 2;
	Employee** newtab = new Employee * [this->capacity];
	for (int i = 0; i < this->nbEmp; i++)
	{
		newtab[i] = this->emp[i];
	}
	for (int i = this->nbEmp; i < this->capacity; i++)
	{
		newtab[i] = nullptr;
	}
	delete[] this->emp;
	this->emp = nullptr;
	this->emp = newtab;
}



Entreprise::~Entreprise()
{
}
