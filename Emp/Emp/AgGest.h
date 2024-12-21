#pragma once
#include "Agent.h"
#include "gestionnaire.h"
class AgGest :public Agent,public gestionnaire
{
public:
	AsgGest(int, double, string, string);
	void Calculer_salaire() override;
	~AgGest();
};

