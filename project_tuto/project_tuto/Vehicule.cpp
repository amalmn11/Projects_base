#include "Vehicule.h"
#include <iostream>

Vehicule::Vehicule()
{
	this->marque = "";
	this->vitesse = 0;
}

Vehicule::Vehicule(string marque, int vitesse)
{
	this->marque = marque;
	this->vitesse = vitesse;
}

Vehicule::Vehicule(const Vehicule& v)
{
	cout << "salma" << endl;
	this->vitesse = v.vitesse;
	this->marque = v.marque;
}

void Vehicule::afficher()
{
	cout << this->marque << endl;
	cout << this->vitesse << endl;
}

void Vehicule::frainer()
{
	this->vitesse = 0;
}

void Vehicule::avancer()
{
	this->vitesse = 100;
}
