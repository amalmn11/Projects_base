#include "Arith.h"
#include "Error.h"
#include "ErrorExecution.h"
#include "ErrorLogic.h"

Arith::Arith():a(1), b(2)
{
}


Arith::Arith(int a, int b): a(a),b(b)
{
}


int  Arith::add()
{ 
	return this->a+this ->b;
}


bool Arith::is_positive()
{
	//teste aleatoire 
	if (this->a < 0)
	{
		ErrorLogic r;
		throw r;
		return false;
	}
	return true;
}


bool Arith::is_negative()
{
	//teste aleatoire 
	if (this->a > 0)
	{
		ErrorLogic r;
		throw r;
		return false;
	}
	return true;
}


int Arith::division()
{
	if (this->b == 0)
	{
		ErrorExecution r;
		throw r;
	}
	return a / b;
}