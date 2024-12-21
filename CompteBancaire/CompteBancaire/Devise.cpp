#include "Devise.h"

using namespace ILISI2;

Devise::Devise(std::string code, double amount):code(code), amount(amount)
{
}


Devise* ILISI2::Devise::ConvertTo(std::string code)
{
    return nullptr;
}

std::string ILISI2::Devise::to_string() const
{
    //c'est to_string de std
    return std::to_string(this->amount)+" "+ this->code;
}


Devise::~Devise()
{
}
