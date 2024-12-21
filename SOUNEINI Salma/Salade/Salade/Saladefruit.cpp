#include "Saladefruit.h"

Saladefruit::Saladefruit(int c):capacity(c),nbrfruit(0)
{
	this->fruit = new Fruit * [this->capacity];
	for (int i = 0; i < this->capacity; i++)
	{
		this->fruit[i] = nullptr;
	}
}

void Saladefruit::ajouter( Fruit& F)
{
	//j'ai besoin de fonction resize mais il ma reste pas le temp
	this->fruit[this->nbrfruit++] = &F;
}

void Saladefruit::afficher() const
{
	
}

bool Saladefruit::Kernel()
{
	for (int i = 0; i < this->nbrfruit; i++)
	{
		this->fruit[i]->Kernel();
	}
	return false;
}

Saladefruit::~Saladefruit()
{
	for (int i = 0; i < this->nbrfruit; i++)
	{
		delete this->fruit[i];
		this->fruit[i] = nullptr;
	}
	delete[] this->fruit;
	this->fruit = nullptr;
}
