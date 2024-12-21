#include "Transaction.h"

ILISI2::Transaction::Transaction(std::string type, Devise* amount, std::string Date):type(type), amount(amount), Date(Date)
{
}

void ILISI2::Transaction::printTransaction() const
{
	//affichage de cette forme 
	//exp : debut "+200.00 'on' DATE"
	std::cout << this->type;

}

ILISI2::Transaction::~Transaction()
{
}
