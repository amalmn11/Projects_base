#pragma once

#include <string>
#include<iostream>
namespace ILISI2
{
	class Client
	{
	private:
		static int count;
		std::string first_name;
		std::string Last_name;
	public:
		Client(std::string, std::string);
		void afficherclient() const;
		~Client();
	};

}

