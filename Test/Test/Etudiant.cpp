
#include "Etudiant.h"

//definition des methodes 

Etudiant::Etudiant() {
	// Constructeur par d�faut
}

Etudiant::~Etudiant() {
	// Destructeur
}

bool Etudiant::major()
{
	
	if (age > 17) return true;
	else return false; 
}