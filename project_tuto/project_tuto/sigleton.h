#pragma once
#include <string>
using namespace std;

class sigleton
{
	private:
		static int compt;
		int id;
		static sigleton* instance;
		sigleton();
		sigleton(int);
		sigleton(const sigleton& u) = delete;
		sigleton& operator=(const sigleton& u) = delete;
	public:
		
		static sigleton& createur();
		void afficher();
		//sigleton(int);
};

