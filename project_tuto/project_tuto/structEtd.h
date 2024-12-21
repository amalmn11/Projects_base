#pragma once
using namespace std;
#include <string>

struct StructEtd
{
private:
	string nom;
	string prenom;
	int age;
	string CNE;
public: 
	int valider();
	//Etudiant();
	StructEtd(int, string, string);
	void afficher();
};
//int valider();


