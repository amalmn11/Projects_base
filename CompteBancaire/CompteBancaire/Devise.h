#pragma once
#include<string>
namespace ILISI2
{
	class Devise
	{
		private:
		std::string code;
		double amount;
		//double rate;
		public:
			Devise(std::string, double);
			Devise* ConvertTo(std::string code);
			std::string to_string() const;
			~Devise();

	};

}

