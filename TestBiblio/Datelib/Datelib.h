#pragma once
#include <iostream>

// Déclaration de la classe
class Datelib {
private:
    int jour;
    int mois;
    int annee;

public:
    // Constructeur
    Datelib(int jour, int mois, int annee) : jour(jour), mois(mois), annee(annee) {}


    void afficherdate() const
    {
        std::cout << "Date: " << jour << "/" << mois << "/" << annee << std::endl;
    }

};
