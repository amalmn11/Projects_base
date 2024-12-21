#include <iostream>
//#include "structEtd.h"
//#include "Etudiant.h"
#include "Vehicule.h"
#include "sigleton.h"
#include "Complexe.h"

int main()
{	
	Complexe* z1 = new Complexe(2,3);
	//Complexe* z2 = new Complexe(2,4);

	//Complexe* z3 = *z1 + *z2;
	Complexe* z4;
	z4 = *z1 + 4;
	z4->Affichage();
	//z3->Affichage();


	//on a creer ici une reference sur l'objet pointe par * instance
	/*
	sigleton& S1= sigleton::createur();
	S1.afficher();
	sigleton& S2 = sigleton::createur();
	S2.afficher();
	*/

	/*
	Vehicule  V1;
	Vehicule V2 = Vehicule(V1);
	V2.afficher();
	V2.avancer();
	V2.afficher();
	V1.afficher();
	//V2.afficher();
	
	*/
	



	//declaration de variavle de refernce
	/*
	Vehicule  V1;
	Vehicule &V3 = V1;
	V3.avancer();
	V1.afficher();
	//modification appliquer sur V1 aussi car V1 et V3 sont des nom pour la meme case 
	*/
	






	/*
	//passage par adress
	Vehicule V1;
	Vehicule V2 = Vehicule(&V1);
	V2.afficher();
	*/

	
	
}



































/*
int main()
{

	// Déclaration d'une fonction au lieu d'une instance
	Etudiant e1();  // Ceci déclare une fonction, pas un objet

	// Essai d'accéder à l'âge de e1
	// Cela entraînera une erreur, car e1 n'est pas un objet
	/*
	teste de structure StructEtd
	StructEtd E1(12,"s","sv");
	E1.afficher();

	//E1.valider();
	StructEtd E2(13, "d", "sf");
	//E2.valider();
	E2.afficher();
	*/
/*
}
*/
