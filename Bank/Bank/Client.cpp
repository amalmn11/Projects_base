#include "Client.h"

using namespace std;
#include<iostream>

int Bank::Client::count = 0;

Bank::Client::Client(std::string n, std::string m):id_client(++count),First_name(n), Last_name(m)
{
}

void Bank::Client::afficherClient() const
{
	cout << "L'id de propritaire :"<< this->id_client << endl;
	cout<< this->First_name<< endl;
	cout << this->Last_name << endl;
}

Bank::Client::~Client()
{
}
