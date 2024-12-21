#include <iostream>
#include "Vehicule.h"
#include "Unique.h"

int main()
{
	//Unique U1;
	//U1.afficher();


	//sa me permet de creer juste un seul objet 
	/*
	Unique::createur();
	Unique::createur();
	*/


	/*
	//meme prob reste en peut creer des obj simulaire by using c.avec parm
	Unique U2(1);
	U2.afficher();
	Unique U1(1);
	U1.afficher();
	*/
	
	/*
	* delete sur operator = et c.de recopie
	* 
	//Unique U3=U2;//appel de constructeur de recopie comme  Unique U3=Unique(U2);
	Unique U3;
	U3 = U2;//operateur d'affectation
	
	U3.afficher();
	*/
	

	/********declaration statique et dynamique + destructeur *********/
	/*
	//creation avec constructeur ans parametre 
	//creation statique
	Vehicule V1;
	V1.Afficher();

	//creation dynamique 
	Vehicule* V2;
	V2 = new Vehicule(1, "BMW", 200,20);
	V2->Afficher();
	delete V2;
	return 0;
	*/
	
}

