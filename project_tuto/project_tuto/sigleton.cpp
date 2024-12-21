#include "sigleton.h"
#include <iostream>

int sigleton::compt = 0;

sigleton::sigleton()
{
	this->id = compt++;
}

sigleton::sigleton(int id)
{
	this->id = id;
}

sigleton* sigleton::instance = nullptr;

sigleton& sigleton::createur()
{
	//sigleton* U1=nullptr;
	if (!instance)
	{
		//U1=new sigleton();
		instance = new sigleton();
	}
	return *instance;
}

void sigleton::afficher()
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



