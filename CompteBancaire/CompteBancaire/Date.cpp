#include "Date.h"



Date::Date(int j, int m, int a):jour(j),mois(m),annee(a)
{
}

void Date::afficher_date() const
{
	cout << " jour  : " << this->jour << endl;
	cout << " mois  : " << this->mois << endl;
	cout << " annee  : " << this->annee << endl;
}
