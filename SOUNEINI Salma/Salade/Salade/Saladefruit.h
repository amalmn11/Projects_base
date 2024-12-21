#pragma once
#include "fruit.h"

class Saladefruit
{
	
	private:
		Fruit** fruit;
		int nbrfruit;
		int capacity;
	public:
		Saladefruit(int);
		void ajouter(Fruit&);
		void afficher() const;
		bool Kernel();
		~Saladefruit();
	
};

