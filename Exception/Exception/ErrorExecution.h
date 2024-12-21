#pragma once
#include "Error.h"

class ErrorExecution :public Error
{
public:
	void afficher() const;
};

