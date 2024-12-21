#pragma once
using namespace std;
#include "Client.h"
#include "Devise.h"
#include "Transaction.h"
class Compte
{
private:
	int id;
	int code;
	Client* proprietaire;
	double solde;
	Transaction* historique[20];
public:
	Compte(int, int,Client*,Devise);
};

