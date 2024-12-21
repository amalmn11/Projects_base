#pragma once
using namespace std;
#include <iostream>

class Complexe
{
private:
	double re;
	double img;
public:
	Complexe();
	Complexe(double,double);
	Complexe(const Complexe&);
	Complexe* operator+(const Complexe& C)const;
	Complexe* operator+(const double& C)const;
	Complexe* operator-(const Complexe& C)const;
	Complexe* operator-(const double& C)const;
	Complexe* operator*(const Complexe& C)const;
	Complexe* operator/(const Complexe& C)const;

	void Affichage();
};

