#include <iostream>
#include<string>
using namespace std;
#include "ArbreBinaire.h"


int main()
{
    ArbreBinaire tree;

    // Construire un arbre binaire
    tree.insert("S");        // Racine
    tree.insert("a");         // Fils gauche
    tree.insert("l");        // Fils droit
    tree.insert("m");         // Fils gauche du fils gauche
    tree.insert("a");         // Fils droit du fils gauche


    cout << "Level-order Traversal of the Binary Tree: ";
    tree.AffichageLargeur();


    if (tree.rechercher("m")) cout << "m existe dans l'arbre" << endl;
    else cout << "m n'existe pas dans l'arbre" << endl;

    return 0;
}
