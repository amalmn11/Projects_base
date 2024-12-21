#pragma once
using namespace std;
#include <string>

class Vehicule
{
private:
	string marque;
	int vitesse;

public:
	Vehicule();
	Vehicule(string, int);
	//Vehicule(Vehicule* v); //tester juste passage par adresse
	Vehicule(const Vehicule& v);
	void afficher();
	void frainer();
	void avancer();
};

