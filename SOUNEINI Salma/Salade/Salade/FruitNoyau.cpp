#include "FruitNoyau.h"

FruitNoyau::FruitNoyau(string f):Fruit(f)
{
}

bool FruitNoyau::Kernel()
{
    if (this->noyau == "avec noyau") return true;
    return false;
}

string FruitNoyau::show_type()
{
    return this->noyau;
}
