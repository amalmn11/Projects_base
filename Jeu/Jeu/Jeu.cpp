#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

// Classe de base : Personnage
class Personnage {
protected:
    std::string nom;
   
    int attaque;

public:
    int pointsDeVie;
    Personnage(std::string nom, int vie, int attaque)
        : nom(nom), pointsDeVie(vie), attaque(attaque) {}

    virtual void attaquer(Personnage& cible) {
        std::cout << nom << " attaque et inflige " << attaque << " points de dégâts.\n";
        cible.pointsDeVie -= attaque;
    }

    bool estVivant() const {
        return pointsDeVie > 0;
    }

    virtual void afficherStatut() const {
        std::cout << nom << " - Vie: " << pointsDeVie << "\n";
    }

    std::string getNom() const {
        return nom;
    }
};

// Classe dérivée : Guerrier
class Guerrier : public Personnage {
public:
    Guerrier(std::string nom) : Personnage(nom, 100, 15) {}

    void attaquer(Personnage& cible) override {
        int bonus = rand() % 6;  // Attaque de base + bonus aléatoire
        std::cout << nom << " frappe avec une épée et inflige " << (attaque + bonus) << " points de dégâts.\n";
        cible.pointsDeVie -= (attaque + bonus);
    }
};

// Classe dérivée : Mage
class Mage : public Personnage {
private:
    int mana;

public:
    Mage(std::string nom) : Personnage(nom, 80, 10), mana(50) {}

    void attaquer(Personnage& cible) override {
        if (mana >= 10) {
            std::cout << nom << " lance un sort de feu, infligeant " << (attaque * 2) << " points de dégâts.\n";
            cible.pointsDeVie -= (attaque * 2);
            mana -= 10;
        }
        else {
            std::cout << nom << " n'a pas assez de mana et inflige une attaque faible de " << attaque << " points de dégâts.\n";
            cible.pointsDeVie -= attaque;
        }
    }

    void afficherStatut() const override {
        std::cout << nom << " - Vie: " << pointsDeVie << ", Mana: " << mana << "\n";
    }
};

// Classe du Jeu
class Jeu {
public:
    void jouer() {
        Guerrier joueur1("Guerrier");
        Mage joueur2("Mage");

        Personnage* joueurActuel = &joueur1;
        Personnage* adversaire = &joueur2;

        while (joueur1.estVivant() && joueur2.estVivant()) {
            joueurActuel->attaquer(*adversaire);
            adversaire->afficherStatut();

            // Échange les rôles de joueur et d'adversaire
            std::swap(joueurActuel, adversaire);

            // Pause entre les tours
            std::cout << "Appuyez sur Entrée pour continuer...\n";
            std::cin.get();
        }

        // Annonce du gagnant
        if (joueur1.estVivant()) {
            std::cout << joueur1.getNom() << " a gagné le combat !\n";
        }
        else {
            std::cout << joueur2.getNom() << " a gagné le combat !\n";
        }
    }
};

int main() {
    std::srand(static_cast<unsigned int>(std::time(0)));

    Jeu jeu;
    jeu.jouer();
    return 0;
}
