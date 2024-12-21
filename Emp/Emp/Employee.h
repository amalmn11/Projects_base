#pragma once

using namespace std;
#include<string>

class Employee
{
private:
	static double Taux_horaire;
	double nbr_heure;
	string Nom;
	string Prenom;
	protected: 
		double salaire;
public:
	Employee(double, string, string);
	//static void initializeTaux(const double&);
	virtual void Calculer_salaire();
	virtual void afficher() const;
	~Employee();
};
