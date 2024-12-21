#include <iostream>
#include <pch.h>


string Inverser_chaine(string t)
{
	Stack<int> R;
	for (int i = 0; i < t.length(); i++)
	{
		R.Push(t[i]);
	}

	for (int i = 0; i < t.length(); i++)
	{
		t[i] = R.Pop();
	}
	return t;
}

 
bool is_palindrome(string t)
{
	if (Inverser_chaine(t) == t) return true;
	return false;
}

int main()
{
	string chaine = "RADAR";
	string chaine2 = Inverser_chaine(chaine);

	cout<<chaine<<" "<< chaine2 << endl ;

	if (is_palindrome(chaine))
	{
		cout << chaine << " est palindrom " << endl;
	}
	else cout << chaine << " n'est pas palindrom " << endl;
	
}