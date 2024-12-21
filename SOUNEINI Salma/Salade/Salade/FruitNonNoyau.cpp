#include "FruitNonNoyau.h"

FruitNonNoyau::FruitNonNoyau(string f):Fruit(f)
{
}

bool FruitNonNoyau::Kernel()
{
    if (this->noyau == "avec noyau") return true;
    return false;
}

string FruitNonNoyau::show_type()
{
    return this->noyau;
}
