#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono> // pour gérer le temps

// Classe de base pour tous les personnages
class Character {
protected:
    int x, y; // Position du personnage sur la grille

public:
    Character(int startX, int startY) : x(startX), y(startY) {}

    virtual void move(int gridSize) = 0; // Méthode virtuelle pure pour le déplacement

    int getX() const { return x; }
    int getY() const { return y; }
};

// Classe pour le chasseur
class Hunter : public Character {
public:
    Hunter(int startX, int startY) : Character(startX, startY) {}

    void move(int gridSize) override {
        char direction;
        std::cout << "Entrez une direction (z=haut, s=bas, q=gauche, d=droite) : ";
        std::cin >> direction;

        switch (direction) {
        case 'z': if (y > 0) y--; break;
        case 's': if (y < gridSize - 1) y++; break;
        case 'q': if (x > 0) x--; break;
        case 'd': if (x < gridSize - 1) x++; break;
        default: std::cout << "Direction invalide!\n"; break;
        }
    }
};

// Classe pour les monstres
class Monster : public Character {
public:
    Monster(int startX, int startY) : Character(startX, startY) {}

    void move(int gridSize) override {
        // Déplacement aléatoire
        int direction = rand() % 4;
        switch (direction) {
        case 0: if (y > 0) y--; break;            // Haut
        case 1: if (y < gridSize - 1) y++; break; // Bas
        case 2: if (x > 0) x--; break;            // Gauche
        case 3: if (x < gridSize - 1) x++; break; // Droite
        }
    }
};

// Classe pour gérer la grille
class Grid {
private:
    int size;
    std::vector<std::vector<char>> grid;

public:
    Grid(int gridSize) : size(gridSize), grid(gridSize, std::vector<char>(gridSize, '.')) {}

    void draw(const Hunter& hunter, const std::vector<Monster>& monsters) {
        // Réinitialiser la grille
        for (auto& row : grid) std::fill(row.begin(), row.end(), '.');

        // Placer le chasseur
        grid[hunter.getY()][hunter.getX()] = 'H';

        // Placer les monstres
        for (const auto& monster : monsters) {
            grid[monster.getY()][monster.getX()] = 'M';
        }

        // Afficher la grille
        for (const auto& row : grid) {
            for (char cell : row) {
                std::cout << cell << ' ';
            }
            std::cout << '\n';
        }
    }

    int getSize() const { return size; }
};

// Classe principale du jeu
class Game {
private:
    Grid grid;
    Hunter hunter;
    std::vector<Monster> monsters;
    int movesLeft;
    std::chrono::system_clock::time_point startTime;
    int timeLimit; // Limite de temps en secondes

public:
    Game(int gridSize, int numMonsters, int timeLimitInSeconds)
        : grid(gridSize), hunter(gridSize / 2, gridSize / 2), timeLimit(timeLimitInSeconds) {
        srand(time(0));
        // Ajouter des monstres à des positions aléatoires
        for (int i = 0; i < numMonsters; ++i) {
            int x = rand() % gridSize;
            int y = rand() % gridSize;
            monsters.emplace_back(x, y);
        }
    }

    void run() {
        startTime = std::chrono::system_clock::now();

        while (true) {
            // Vérifier si le temps est écoulé
            auto currentTime = std::chrono::system_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime);
            if (elapsed.count() >= timeLimit) {
                std::cout << "Temps écoulé! Vous avez échoué.\n";
                break;
            }

            std::cout << "Temps restant : " << (timeLimit - elapsed.count()) << " secondes\n";
            std::cout << "Monstres restants : " << monsters.size() << "\n";

            grid.draw(hunter, monsters);

            // Déplacer le chasseur
            hunter.move(grid.getSize());

            // Déplacer les monstres
            for (auto& monster : monsters) {
                monster.move(grid.getSize());
            }

            // Vérifier les collisions entre le chasseur et les monstres
            monsters.erase(std::remove_if(monsters.begin(), monsters.end(),
                [this](const Monster& monster) {
                    return monster.getX() == hunter.getX() &&
                        monster.getY() == hunter.getY();
                }),
                monsters.end());

            // Si tous les monstres sont capturés, le joueur gagne
            if (monsters.empty()) {
                std::cout << "Félicitations ! Vous avez attrapé tous les monstres !\n";
                break;
            }
        }
    }
};

int main() {
    Game game(10, 5, 30); // Grille de taille 10x10, 5 monstres, limite de temps de 30 secondes
    game.run();
    return 0;
}
