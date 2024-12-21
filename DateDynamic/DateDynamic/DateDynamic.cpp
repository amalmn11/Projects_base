#include <iostream>
#include "pch.h"
int main()
{
    DateLibDyn* date = new DateLibDyn(03, 11, 2024);
    date->afficherdate();
    delete date;
}
