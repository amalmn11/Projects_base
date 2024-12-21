#include "AgGest.h"
#include "Agent.h"
#include "gestionnaire.h"


AgGest::AgGest(int ventes, double nbr_heure, string Nom, string Prenom):Agent(ventes, nbr_heure, Nom, Prenom), gestionnaire(nbr_heure, Nom, Prenom)
{
}

void AgGest::Calculer_salaire()
{
	this->salaire = this->Agent::Calculer_salaire() + this->gestionnaire::Calculer_salaire();
}
