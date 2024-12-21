#pragma once
#include "Client.h"
#include "Devise.h"
#include "Transaction.h"
#include "Date.h"
#include <vector>

class Compte
{
private:
	int Numero_compte;
	Client* client;
	Devise* solde;
	vector<Transaction*>* transaction;
	Date* Date_ouveture;
public: 
	Compte(int, Client*, Devise*, vector<Transaction*>*);
};

