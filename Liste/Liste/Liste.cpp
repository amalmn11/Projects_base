
#include <iostream>
#include "Liste.h"

int main()
{
    Liste<int>* p=new Liste<int>(5);
    p->insererFin(3);
    p->insererFin(4);
    p=p->insererDebut(11);
    p->supprimerFin();
    p = p->supprimerdebut();

    p->afficherListe();
}
