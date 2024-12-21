// template.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>

template<class T>
T max(T a, T b)
{
    return((a > b) ? a : b);
}
int main()
{
    int max1 = max(10, 20);
    float max12 = max<float>(10.0, 20.5);
    char max13 = max('a', 'A');
    std::cout<< max1 <<std::endl;
    std::cout << max12 << std::endl;
    std::cout << max13 << std::endl;
}
