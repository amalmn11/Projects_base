#pragma once


using namespace std;
#include<string>
class Compte;

class Client
{
private:
	string CIN;
	string nom;
	string prenom;
	Compte* comptes[20];
public:
	Client(string, string, string, Compte* [20]);
	void deposer();
};

