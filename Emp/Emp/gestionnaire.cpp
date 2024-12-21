#include "gestionnaire.h"
#include<iostream>
double gestionnaire::salaireheb = 30.00;

gestionnaire::gestionnaire(double nbr_heure, string Nom, string Prenom):Employee(nbr_heure, Nom, Prenom)
{
	this->Calculer_salaire();
}

void gestionnaire::afficher() const
{
	cout << endl;
	cout << "Les informations du gestionnaire :" << endl;
	cout << "formule de salaire est :salaire + salaire_hebedomadaire" << endl;
	cout << "Le salaire hebdomadaire est  :" << gestionnaire::salaireheb << endl;
	Employee::afficher();
	cout << endl;
}

void gestionnaire::Calculer_salaire()
{
	this->salaire += gestionnaire::salaireheb;
}

gestionnaire::~gestionnaire()
{
}
