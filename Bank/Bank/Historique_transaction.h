#pragma once
#include "Transaction.h"
namespace Bank
{
	class Historique_transaction
	{
	private:
		Transaction** history;
		int capacity;
		int Transaction_count;
	public:
		Historique_transaction();
		void addtransaction(Transaction&);
		void resize();
		~Historique_transaction();
	};
}


