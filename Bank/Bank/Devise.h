#pragma once
#include<string>
namespace Bank
{
	class Devise
	{
	private:
		std::string code;
		double montant;
	public:
		Devise(std::string, double);
		void operator+=(const Devise&);
		bool operator==(const Devise&);
		std::string to_string() const;
		~Devise();

	};
}

