#pragma once
#include "Employee.h"
class Agent :virtual public Employee
{
private:
	static double commission;
	double indemnite;
	int ventes;
public:
	Agent(int, double, string, string);
	void afficher() const override;
	double calculer_indemnite();
	void Calculer_salaire() override;
	~Agent();
};

