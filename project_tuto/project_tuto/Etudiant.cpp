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
	
	std::cout << "Constructeur appelé !" << std::endl;
	this->age = 19; // Initialisation de l'âge
}
/*Etudiant::Etudiant(int a, string b, string c)
{
	this->age = a;
	this->nom = b;
	this->prenom = c;
}*/

