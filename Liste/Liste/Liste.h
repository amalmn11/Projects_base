#pragma once

using namespace std;
template <class MyType>
class Liste
{
	private:
		MyType value;
		Liste* suivant;

	public:
		Liste(MyType);
		void afficherListe() ;
		Liste<MyType>* insererDebut(MyType);
		void insererFin(MyType);
		Liste<MyType>*  supprimerdebut();
		void supprimerFin();
		~Liste();

};

template<class MyType>
inline Liste<MyType>::Liste(MyType var):suivant(nullptr),value(var)
{
}

template<class MyType>
inline void Liste<MyType>::afficherListe() 
{
	Liste* courant = this;
	while (courant)
	{
		cout<<courant->value<<" "<< endl;
		courant = courant->suivant;

	}
}

template<class MyType>
inline Liste<MyType>* Liste<MyType>::insererDebut(MyType var)
{
	Liste<MyType>* t = new Liste<MyType>(var);
	t->suivant = this;
	return t;
}

template<class MyType>
inline void Liste<MyType>::insererFin(MyType var)
{
	Liste<MyType>* t=new Liste<MyType>(var);
	Liste<MyType>* courant = this;
	while (courant->suivant) courant = courant->suivant;
	courant->suivant = t;

}

template<class MyType>
inline Liste<MyType>* Liste<MyType>::insererPos(int pos, MyType var)
{
	Liste<MyType>* courant;
	if (pos == 0)
	{
		insererDebut();

	}
}

template<class MyType>
inline Liste<MyType>* Liste<MyType>::supprimerdebut()
{
	Liste<MyType>* courant = this->suivant;
	return courant;
}

template<class MyType>
inline void Liste<MyType>::supprimerFin()
{
	Liste<MyType>* courant = this;
	while (courant->suivant->suivant) courant = courant->suivant;
	courant->suivant = nullptr;
}

template<class MyType>
inline void Liste<MyType>::supprimerPos()
{
	return 0;
}

template<class MyType>
inline Liste<MyType>::~Liste()
{

}
