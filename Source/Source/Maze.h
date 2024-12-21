#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

class Maze {
private:
    static const int WINDOW_WIDTH = 800;
    static const int WINDOW_HEIGHT = 600;
    static const int TILE_SIZE = 40; // Taille d'une case de la grille

    // La grille du labyrinthe
    std::vector<std::vector<int>> grid;
    sf::Color wallColor;
    sf::Color pathColor;

public:
    // Constructeur par d�faut avec un labyrinthe pr�d�fini
    Maze();

    // Constructeur pour un labyrinthe personnalis�
    Maze(const std::vector<std::vector<int>>& customGrid, sf::Color, sf::Color);


    // M�thode pour dessiner le labyrinthe dans la fen�tre SFML
    void draw(sf::RenderWindow& window) const;

    //verifier une position est ce qu'il est un chemain 
    bool isPath(int x, int y) const;

    // Destructeur
    ~Maze();

};
