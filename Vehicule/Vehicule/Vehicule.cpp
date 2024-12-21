#include "Vehicule.h"
#include <iostream>

Vehicule::Vehicule()
{
	//on peut donner des valeurs par defaults : on peut le laisse vide 
	this->historique_km= new int();
	*(this->historique_km) = 12;
	this->id = 1;
	this->marque = ' ';
	this->vitesse = 0;
}


Vehicule::Vehicule(int id,string marque,int vitesse,int hist_km)
{
	this->id = id;
	this->marque = marque;
	this->vitesse = vitesse;
	this->historique_km = new int();
	*(this->historique_km) = hist_km;
}


void Vehicule::Afficher()
{
	cout << "L'id : " << this->id << endl;
	cout << "La marque : " << this->marque << endl;
	cout << "La vitesse: " << this->vitesse << endl;
	cout << "La historique_km: " << *(this->historique_km) << endl;
}

void Vehicule::freiner()
{
	this->vitesse=0;
}

void Vehicule::avancer()
{
	this->vitesse+=20;
}

Vehicule::~Vehicule()
{
	delete this->historique_km;
}
