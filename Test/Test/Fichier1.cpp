#include <iostream> // Bibliothèque pour l'entrée et la sortie
#include "Etudiant.h"
//pouquoi on fait include de fichier .h non pas de fichier .cpp


int main() {
    Etudiant E1 = Etudiant();
    E1.Nom = "salma";
    E1.age = 18;
    E1.CNE = "Q1234";
    E1.Prenom = "SS";
    cout << "Le Nom :"<<E1.Nom << endl;
    cout << "Le Prenom :" << E1.Prenom << endl;
    cout << "Le CNE :" << E1.CNE << endl;
    cout << "Le Age :" << E1.age << endl;
}
