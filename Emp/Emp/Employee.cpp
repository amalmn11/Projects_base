#include "Employee.h"
#include<iostream>

double Employee::Taux_horaire = 100.00;

Employee::Employee(double nbr_heure, string Nom, string Prenom):nbr_heure(nbr_heure), Nom(Nom), Prenom(Prenom),salaire(0)
{
	this->Calculer_salaire();
}


void Employee::Calculer_salaire()
{
	this->salaire = this->Taux_horaire * this->nbr_heure;
}

void Employee::afficher() const
{
	cout << "Le Taux Horaire est :" << Employee::Taux_horaire << endl;
	cout <<"Le nom :" << this->Nom << endl;
	cout << "Le prenom :" << this->Prenom << endl;
	cout << "Le nombre d'heure travaille est  :" << this->nbr_heure << endl;
	cout << "Le salaire est :" << this->salaire << endl;
}

Employee::~Employee()
{
}
