#include "Agent.h"
#include<iostream>

double Agent::commission = 50.0;


Agent::Agent(int ventes, double nbr_heure, string Nom, string Prenom)
	:Employee(nbr_heure, Nom, Prenom), ventes(ventes)
{
	this->Calculer_salaire();
}

void Agent::afficher() const
{
	cout << endl;
	cout << "Les informations de l'agent :" << endl;
	cout << "formule de salaire est : salaire + indemnite" << endl;
	cout << "Commission des agents est  :" << Agent::commission<< endl;
	cout << "Les ventes est  :" << this->ventes << endl;
	cout << "L'indemnite :" << this->indemnite << endl;
	Employee::afficher();
	cout << endl;
}



double Agent::calculer_indemnite()
{
	return this->indemnite = this->commission * this->ventes;
}

void Agent::Calculer_salaire()
{
	//this->salaire=this->
	this->salaire += this->calculer_indemnite();
}

Agent::~Agent()
{
}
