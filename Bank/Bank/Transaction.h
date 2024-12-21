#pragma once
#include"Devise.h"

using namespace std;
#include<string>

namespace Bank
{
	class Transaction
	{
	private:
		string type;
		Devise* montant;
		string date;
	public:
		Transaction(string, Devise*, string);
		void affichertransaction() const;
		~Transaction();
	};
}


