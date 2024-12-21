#pragma once
#include "transaction.h"
namespace ILISI2
{
	class Historytransaction
	{
	private:

		Transaction** history;
		int Capcity; 
		int transaction_count;
	public:
		Historytransaction();
		void ajoutertransaction(Transaction*);
		void resize();
		void printalltransactions() const;
		~Historytransaction();
	};
}

