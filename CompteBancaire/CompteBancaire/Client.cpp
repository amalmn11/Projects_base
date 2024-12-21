#include "Client.h"

int ILISI2::Client::count = 0;

ILISI2::Client::Client(std::string nom, std::string prenom):first_name(prenom),Last_name(nom),count(++count)
{
}

void ILISI2::Client::afficherclient() const
{
	//affichage;
}

