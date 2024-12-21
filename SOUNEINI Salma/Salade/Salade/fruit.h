#pragma once
#include<iostream>
#include<string>
#include "Saladefruit.h"

using namespace std;
class Fruit:public Saladefruit
{

protected:
	string noyau;
public:
	Fruit(string);
	virtual bool Kernel()=0;
	void afficher() const;
	virtual string show_type()=0;
};

