#pragma once
#include "Employee.h"
class gestionnaire :virtual public Employee
{

private:
	static double salaireheb;
public:
	gestionnaire(double, string, string);
	void afficher() const;
	void Calculer_salaire() override;
	~gestionnaire();
};

