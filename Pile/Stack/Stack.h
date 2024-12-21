#pragma once
#include<iostream>
//int max = 100;
template<class T>
class Stack
{
private:
	int Sommet;
	T Values[100];

public:
	Stack();
	Stack(T);
	bool isEmpty();
	bool isfull();
	void Push(T);
	void Pop();
	int  size();

};

template<class T>
inline Stack<T>::Stack()
{
}

template<class T>
inline Stack<T>::Stack(T tab):sommet(0)
{
	for (int i = 0; i < 100; i++) Values[i] = tab[i];
}

template<class T>
inline bool Stack<T>::isEmpty()
{
	return Sommet == -1;
}

template<class T>
inline bool Stack<T>::isfull()
{
	return Sommet == 100;
}

template<class T>
inline void Stack<T>::Push(T a)
{
	if (isfull()) { std::cout << " Stack plein" << std::endl; exit; }
	Values[++Sommet] = a;
}

template<class T>
inline void Stack<T>::Pop()
{
	if (isEmpty()) { std::cout << " Stack vide" << std::endl; exit; }
	Sommet--;
}

template<class T>
inline int Stack<T>::size()
{
	return 0;
}


