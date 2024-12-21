#pragma once
#include "fruit.h"
class FruitNonNoyau :public Fruit
{
public:
	
	FruitNonNoyau(string);
	bool Kernel() override;
	string show_type() override;
};

