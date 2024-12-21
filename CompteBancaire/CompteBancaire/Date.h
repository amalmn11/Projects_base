#pragma once
#include<iostream>
using namespace std;
class Date
{
private:
	int jour;
	int mois;
	int annee;
public: 
	Date(int, int, int);
	void afficher_date()const;
};

