#pragma once
#include "fruit.h"
#include "JusFruit.h"
class Jus:public JusFruit
{
private:
	Fruit** jus;
public:
	Jus(Fruit**);
};

