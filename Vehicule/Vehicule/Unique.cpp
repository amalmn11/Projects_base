#include "Unique.h"
#include <iostream>

int Unique::compt = 0;

Unique::Unique()
{
	this->id=compt++;
}

Unique::Unique(int id)
{
	this->id = id;
}
/*
Unique::Unique(const Unique& u)
{
	this->id = u.id;
}
*/


Unique& Unique::createur()
{
	if (compt == 0)
	{
		Unique U1;
		return U1;
	}
}

void Unique::afficher()
{
	cout << "L'id : " << this->id << endl;
}

/*
Unique::Unique(int id)
{
	comp
	this->id = id;
}
*/

