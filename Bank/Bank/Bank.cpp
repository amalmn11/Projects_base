

#include <iostream>
#include "Devise.h"
#include "Client.h"
#include "Compte.h"
using namespace Bank;


int main()
{
	Client* C1 = new Client("salma","sn");
	Devise* D = new Devise("MAD", 2000);
	Compte* c = new Compte(C1,D,"27102024");
	c->affichagecompte();
	/*
	Devise* D= new Devise("MAD",2000);
	std::cout << D->Afficher_devise();
	delete D;
	*/


	

}

