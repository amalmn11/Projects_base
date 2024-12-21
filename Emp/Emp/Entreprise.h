#pragma once
#include "Employee.h"

class Entreprise
{
private:
	Employee** emp;
	static int compteur;
	int Id_Entreprise;
	string Nom_Entreprise;
	string adresse;
	int capacity;
	int nbEmp;
	double totalsalaire;
public:
	Entreprise(string, string);
	bool ajouterEmployee(Employee*);
	void afficherall() const;
	void resize();
	~Entreprise();
};

