#include "Complexe.h"

Complexe::Complexe()
{
	this->re = 0;
	this->img = 0;
}

Complexe::Complexe(double r, double i)
{
	this->re = r;
	this->img = i;
}

Complexe::Complexe(const Complexe& c)
{
	this->re = c.re;
	this->img = c.img;
}

/*
//on aura un probleme ici l'hors de desruction de l'objet pointer par Z2 dasn le main (objet inaccessible)
Complexe& Complexe::operator+(const Complexe& C) const
{
	Complexe* z2 = new Complexe();
	z2->re = this->re + C.re;
	z2->img = this->img + C.img;
	return *z2;
	// TODO: insérer une instruction return ici


}

*/

Complexe* Complexe::operator+(const Complexe& C) const
{
	Complexe* z2 = new Complexe();
	z2->re = this->re + C.re;
	z2->img = this->img + C.img;
	return z2;
	// TODO: insérer une instruction return ici


}

Complexe* Complexe::operator+(const double& C) const
{
	Complexe* z2 = new Complexe();
	z2->re = this->re + C;
	z2->img = this->img;
	return z2;
}

Complexe* Complexe::operator-(const Complexe& C) const
{
	Complexe* z2 = new Complexe();
	z2->re = this->re - C.re;
	z2->img = this->img - C.img;
	return z2;
}

Complexe* Complexe::operator-(const double& C) const
{
	Complexe* z2 = new Complexe();
	z2->re = this->re - C;
	z2->img = this->img;
	return z2;
}

Complexe* Complexe::operator*(const Complexe& C) const
{
	Complexe* z2 = new Complexe();
	z2->re = this->re * C.re - this->img * C.img;
	z2->img = this->re * C.re + this->img * C.img;
	return z2;
}

Complexe* Complexe::operator/(const Complexe& C) const
{
	double denom =this->re * C.re + this->img * C.img;
	if (denom == 0) {
		cout<<("Division par zéro");
	}
	Complexe* z2 = new Complexe();
	z2->re = (this->re * C.re + this->img * C.img) / denom;
	z2->img = (this->re * C.re - this->img * C.img) / denom;

	return z2;
}




void Complexe::Affichage()
{
	cout<< "La partie reel : " << this->re <<endl;
	cout << "La partie imaginaire : " << this->img <<"i"<<endl;
}
