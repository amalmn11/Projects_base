#pragma once
#include <string>
using namespace std;


class Unique
{
	private:
		static int compt;
		int id;
		Unique();
		Unique(int);
		Unique(const Unique& u) = delete;
		Unique& operator=(const Unique& u) = delete;
	public:
		static Unique& createur();
		void afficher();
		//Unique(int);
};

