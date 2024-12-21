#include "structEtd.h"
#include <iostream>

int compt = 12;
int StructEtd::valider()
{
	compt++;
	this->age = compt;
	cout << this->age;
	return 0;
} 
StructEtd::StructEtd(int a, string b, string c)
{
	this->age = a;
	this->nom = b;
	this->prenom = c;
}
void StructEtd::afficher()
{
	cout << this->age << endl;
	cout << this->nom << endl;
	cout << this->prenom << endl;
}
/*int valider() {
	cout << "valider";
	return 1;

}
*/