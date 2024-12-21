#include <iostream>
#include <vector>
#include<chrono>
using namespace std;

int main()
{
	//creer un vector
	vector<int> Tab;

	auto start = std::chrono::high_resolution_clock::now();
	//auto end = std::chrono::high_resolution_clock::now();

	for (int i = 0; i <= 10000000; i++)
	{
		Tab.push_back(i);
	}
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration = end - start;

	// Affichage du résultat
	std::cout << "Temps d'execution : " << duration.count() << " secondes" << std::endl;
	//affichage 
	/*
	for (int i = 0; i <= Tab.size(); i++)
	{
		cout << Tab[i] << " ";
	}
	cout <<"Fin"<< endl;
	*/
}
