#pragma once
#include "Point.h"

class Cercle
{
private:
	double Rayon;
	Point centre;
public:
	Cercle();
	Cercle(double,Point);
	Cercle(const Cercle& C);
	void affichage();
	void ModifierRayon(double rayon);
	void Traslatercentre(double centre);
	double SurfaceCercle(double rayon);
	double PerimetreCercle(double rayon);
	bool Egaliter(const Cercle& C)const;

};

