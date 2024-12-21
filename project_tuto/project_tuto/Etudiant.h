#pragma once
using namespace std;
#include <string>


class Etudiant
{
private:
	string nom;
	string prenom;
	int age;
public: 
	bool major();
	Etudiant();
	//Etudiant(int, string, string);
};


/*
ce qui est a l'interieur de la structure est public par defaut 
1- on regroupe les données et les methodes dans une seul structre.
2- on ajoute un niveau de visibilter privé pour les attributs.
donc on obtient la notion de classe.alors en peux remplacer struct par class
*/


/*
l'opration valide s'applique sur l'etudiant elle meme n'est sur un autre etudiant 
c'est por cella on a pas besoin de le passer en parametre car la methode valide il est methode membre donc il est accessible par l'obj actuel 
si on declare un param c'est comme en travailler avec deux etudiant comme call pour le tele on a besoin d'un seul phone qui est phone actuel
*/



