#include "Compte.h"

Compte::Compte(int NCompte, Client* C, Devise* D, vector<Transaction*>* transaction):Numero_compte(NCompte), client(C), solde(D), transaction(transaction)
{
}


