#pragma once
#include<iostream>
template<class Type>
class ListeChaine
{
private:
	Type value;
	ListeChaine* suivant;

public:
	ListeChaine(Type);
	ListeChaine<Type>* insererdebut(Type);
	Type get_value() const;
	void afficherliste() const;
	void insererfin(Type);
	ListeChaine<Type>* Supprimerdebut();
	void SupprimerFin(Type);
	~ListeChaine();

};



template<class Type>
inline ListeChaine<Type>::ListeChaine(Type t) :value(t), suivant(nullptr)
{
}

template<class Type>
inline ListeChaine<Type>* ListeChaine<Type>::insererdebut(Type t)
{
	ListeChaine<Type>* cellule = new ListeChaine<Type>(t);
	cellule->suivant = this;
	return cellule;
}

template<class Type>
inline Type ListeChaine<Type>::get_value() const
{
	return this->value;
}

template<class Type>
inline void ListeChaine<Type>::afficherliste() const
{
	const ListeChaine<Type>* Temp = this;
	while (Temp)
	{
		std::cout << Temp->value << std::endl;
		Temp = Temp->suivant;
	}
}

template<class Type>
inline void ListeChaine<Type>::insererfin(Type t)
{
	ListeChaine<Type>* cellule = new ListeChaine<Type>(t);
	ListeChaine<Type>* crt = this;
	while (crt->suivant) crt = crt->suivant;
	crt->suivant = cellule;
}

template<class Type>
inline ListeChaine<Type>* ListeChaine<Type>::Supprimerdebut()
{
	return this->suivant;
}

template<class Type>
inline void ListeChaine<Type>::SupprimerFin(Type)
{
	ListeChaine<Type>* crt = this;
	while (crt->suivant->suivant) crt = crt->suivant;
	crt->suivant = nullptr;
}

template<class Type>
inline ListeChaine<Type>::~ListeChaine()
{
}
