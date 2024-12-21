#pragma once

#include <string>
using namespace std;


class Vehicule
{
	//attribut
private: 
	int id;
	string marque;
	int vitesse;
	int* historique_km;

public:
	Vehicule();
	//on a la possiblite de declare les parametre sans nom de variable mais dans la deficition .cpp on doit donner les noms par ce que onva travailler avec ces derniers 
	Vehicule(int id,string marque,int vitesse,int hist_km);
	//on va travailler avec l'objet courant c'est pas a peine de mentionner l'objet dans parametres 
	void Afficher();
	void freiner();
	void avancer();
	~Vehicule();
	//methode
};

