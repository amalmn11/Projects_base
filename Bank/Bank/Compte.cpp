#include "Compte.h"
#include "Transaction.h"
using namespace std;
#include<iostream>

//using namespace Bank;

int Bank::Compte::compt = 0;



Bank::Compte::Compte(Client* proprietaire, Devise* solde, string date):id(++compt), proprietaire(proprietaire), solde(solde), date(date)
{
	this->history = new Historique_transaction();
}

bool Bank::Compte::crediter(Devise* solde, string date)
{
	if ( *this->solde == *solde) 
	{
		*this->solde += *solde;
		Transaction* T= new Transaction("+", solde, date);
		this->history->addtransaction(*T);	
		return true;
	}
	return false;
}

bool Bank::Compte::debiter(Devise*, string)
{
}

bool Bank::Compte::transfert(Client*, Devise*)
{
	return false;
}

void Bank::Compte::affichagecompte() const
{
	cout <<"L'id de compte :" << this->id << endl;
	this->proprietaire->afficherClient();
	this->solde->to_string();
}

Bank::Compte::~Compte()
{
}
