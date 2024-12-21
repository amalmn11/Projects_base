#pragma once
#include "fruit.h"


class FruitNoyau : public Fruit
{
public:
	FruitNoyau(string);
	bool Kernel() override;
	string show_type() override;
};

