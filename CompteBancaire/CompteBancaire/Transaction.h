#pragma once
#include "Devise.h"

namespace ILISI2
{
	class Transaction
	{
	private:
		std::string type;
		Devise* amount;//la valeur
		std::string Date;
	public:
		Transaction(std::string, Devise*, std::string);
		void printTransaction() const;
		~Transaction();
	};
}

