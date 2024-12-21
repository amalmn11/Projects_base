#include "pch.h"
#include "DateLibDyn.h"



DateLibDyn::DateLibDyn(int jour, int mois, int annee) :jour(jour), mois(mois), annee(annee)
{
}

void DateLibDyn::afficherdate() const
{
	std::cout << "la date avec biblio dynamic est : " << jour << "/" << mois << "/" << annee << std::endl;
}
