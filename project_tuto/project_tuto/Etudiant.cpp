#include "Etudiant.h"
#include <iostream>


bool Etudiant::major()
{
	if (this->age >= 18)
	{
		cout << "major" << endl;
		return true;
	}
	else {
		cout << " non major" << endl;
		return false;
	} 
}

Etudiant::Etudiant()
{
	
	std::cout << "Constructeur appel� !" << std::endl;
	this->age = 19; // Initialisation de l'�ge
}
/*Etudiant::Etudiant(int a, string b, string c)
{
	this->age = a;
	this->nom = b;
	this->prenom = c;
}*/

