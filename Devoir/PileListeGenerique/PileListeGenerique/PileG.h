#pragma once
#include "ListeChaine.h"


template<class T>
class PileG
{
private:
	ListeChaine<T>* sommet;
	int capacity;
	int nbelm;
public:
	PileG(int);
	void afficher();
	void empiler(T);
	T top();
	bool is_empty();
	bool is_full();
	void depiler();
	~PileG();

};

template<class T>
inline PileG<T>::PileG(int c) :nbelm(0), capacity(c), sommet(nullptr)
{
}

template<class T>
T PileG<T>::top() {
	if (is_empty()) {
		throw std::underflow_error("La pile est vide !");
	}
	return this->sommet->get_value(); // Suppose que ListeChaine a une méthode get_value()
}

template<class T>
inline void PileG<T>::afficher()
{
	if (is_empty())
	{
		throw std::underflow_error("la pile est vide ");
	}
	this->sommet->afficherliste();
}

template<class T>
inline void PileG<T>::empiler(T a)
{
	if (is_full())
	{
		throw std::overflow_error("la pile est full");
	}
	if (sommet == nullptr)
	{
		ListeChaine<T>* nv = new ListeChaine<T>(a);
		sommet = nv;

	}
	else
	{
		this->sommet = this->sommet->insererdebut(a);
	}
	this->nbelm++;

}


template<class T>
inline void PileG<T>::depiler()
{
	if (is_empty())
	{
		throw std::underflow_error("la pile est vide ");
	}
	this->sommet = this->sommet->Supprimerdebut();
	this->nbelm--;
}

template<class T>
inline bool PileG<T>::is_empty()
{
	if (nbelm == 0) return true;
	return false;
}

template<class T>
inline bool PileG<T>::is_full()
{
	if (nbelm == capacity) return true;
	return false;
}


template<class T>
inline PileG<T>::~PileG()
{
}

