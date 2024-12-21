#include "Historique_transaction.h"
#include "Transaction.h"


Bank::Historique_transaction::Historique_transaction():capacity(4), Transaction_count(0)
{
	//creation de historique transaction
	this->history=new Transaction * [this->capacity];
	for (int i = 0; i < this->capacity; i++)
	{
		this->history[i] = nullptr;
	}
}


void Bank::Historique_transaction::addtransaction(Transaction& T)
{
	if (this->Transaction_count == this->capacity)
	{	
		this->resize();
	}
	this->history[this->Transaction_count++] = &T;
}


void Bank::Historique_transaction::resize()
{
	this->capacity *= 2;
	Transaction** newtab = new Transaction * [this->capacity];
	for (int i = 0; i < this->Transaction_count; i++)
	{
		newtab[i] = this->history[i];
	}
	for (int i = Transaction_count; i < this->capacity; i++)
	{
		newtab[i] = nullptr;
	}
	delete [] this->history;
	this->history = newtab;//donc ici history va pointeer sur new tableau resizer 
}



Bank::Historique_transaction::~Historique_transaction()
{
	for (int i = 0; i < this->Transaction_count; i++)
	{
		delete this->history[i];
	}
	delete [] this->history;//pour suppirmer tous le taleau n'est juste la 1ere case
	this->history = nullptr;
}
