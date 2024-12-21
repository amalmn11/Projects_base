#pragma once
#include"Devise.h"
#include"Client.h"
#include "Historique_transaction.h"
using namespace std;

namespace Bank
{
	class Compte
	{
	private:
		static int compt;
		int id;
		Client* proprietaire;
		Devise* solde;
		string date;
		Historique_transaction* history;
	public:
		Compte(Client*, Devise*, string);
		bool crediter(Devise*,string);
		virtual	bool debiter(Devise*, string)=0;
		virtual bool transfert(Client*, Devise*)=0;
		void affichagecompte()const;
		~Compte();
	};
}


