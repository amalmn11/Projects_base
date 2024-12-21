#pragma once
#include<string>
using namespace std;

class Noeud
{
public:
		string value;
		Noeud* left;
		Noeud* right;
		Noeud();
		Noeud(string);

};

