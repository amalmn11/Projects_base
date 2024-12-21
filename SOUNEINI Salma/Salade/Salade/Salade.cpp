

#include <iostream>
#include "fruit.h"
#include "Jus.h"
#include "FruitNonNoyau.h"
#include "FruitNoyau.h"
#include "Saladefruit.h"


int main()
{
    Fruit* n = new FruitNonNoyau("avec Noyau");
    Fruit* b = new FruitNoyau("sans Noyau");

    Saladefruit* s = new Saladefruit(10);
    s->ajouter(*n);
    s->ajouter(*b);




    

}

