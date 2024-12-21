#pragma once
#include<iostream>

class DateLibDyn
{
private:
	int jour;
	int mois;
	int annee;
public:
	
	DateLibDyn(int, int, int);
	void afficherdate() const;
};

