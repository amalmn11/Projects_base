#include "Historytransaction.h"

ILISI2::Historytransaction::Historytransaction()
{
	this->history = new Transaction * [this->capacity];
}

void ILISI2::Historytransaction::ajoutertransaction(Transaction*)
{
}

void ILISI2::Historytransaction::resize()
{
}

void ILISI2::Historytransaction::printalltransactions() const
{
}

ILISI2::Historytransaction::~Historytransaction()
{
}
