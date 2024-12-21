#include "Compte.h"

Compte::Compte(int id, int code, Client* client, Devise devise):id(id),code(code), proprietaire(client),solde(devise)
{
}
