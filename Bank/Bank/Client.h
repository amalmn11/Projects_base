#pragma once

#include<string>

namespace Bank
{
	class Client
	{
	private:
		static int count;
		int id_client;
		std::string First_name;
		std::string Last_name;

	public:

		Client(std::string,std::string);
		void afficherClient() const;
		~Client();
	};
}



