#pragma once
template<class T>
#define MAX 100
class Pile
{
private:
	T* Tab;
	int sommet;
	int capacity;
public:
	Pile(int);
	bool isEmpty();
	bool isFull();
	void Push(const T&);
	void Pop();
	int size();
	~Pile();


};



template<class T>
inline Pile<T>::Pile(int a):capacity(a)
{
	this->Tab = new T[capacity];
	This->sommet = 0;
}


template<class T>
inline bool Pile<T>::isEmpty()
{
	return ((this->sommet==0)? true : false);
}

template<class T>
inline bool Pile<T>::isFull()
{
	return ((this->sommet == capacity) ? true : false);
}

template<class T>
inline void Pile<T>::Push(const T&)
{
	this->Tab[this->sommet++] = T;
}

template<class T>
inline void Pile<T>::Pop()
{
	if (this->isEmpty()) {
		delete this->Tab[--this->sommet];
		this->sommet--;
	}
	else {
		std::cout << "la pile est vide "std::endl;
	}
}

template<class T>
inline int Pile<T>::size()
{
	return this->sommet;
}

template<class T>
inline Pile<T>::~Pile()
{
	while (!this->isEmpty()) this->Pop();

}
