#pragma once

#include <string>
using namespace std;

class Etudiant
{
//attribut
public:
	string Nom;
	string Prenom;
	int age;
	string CNE;


public:
	Etudiant();
	~Etudiant();
	bool major();

};

