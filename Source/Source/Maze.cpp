#include "Maze.h"

// Constructeur par d�faut avec une grille pr�d�finie
Maze::Maze()
    : grid({
          {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
          {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
          {1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1},
          {1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1},
          {1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1},
          {1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
          {1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1},
          {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1},
          {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1},
          {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
          {1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1},
          {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1},
          {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1},
          {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
        }),
    wallColor(sf::Color::Green), pathColor(sf::Color::Black)  // Murs rouges, chemins noirs

{}



// Constructeur avec grille personnalis�e
Maze::Maze(const std::vector<std::vector<int>>& customGrid, sf::Color wallColor, sf::Color pathColor)
    : grid(customGrid), wallColor(wallColor), pathColor(pathColor) {}




// Dessin dans la fen�tre SFML
void Maze::draw(sf::RenderWindow& window) const 
{
    //parcourir les lignes de grille 
    for (int i = 0; i <grid.size(); i++) 
    {
        //parcourir les colones de chaque grill 
        for (int j = 0; j < grid[i].size(); j++) 
        {
            //creation de rectongle 
            sf::RectangleShape tile(sf::Vector2f(TILE_SIZE, TILE_SIZE));

            //donner a ce rectongle creer la position 
            tile.setPosition(j * TILE_SIZE, i * TILE_SIZE);

            tile.setFillColor(grid[i][j] == 1 ? wallColor : pathColor);
            window.draw(tile);
        }
    }
}


bool Maze::isPath(int x, int y) const 
{
    // V�rifie si les coordonn�es sont valides
    if (x < 0 || x >=(grid[0].size()) || y < 0 || y >=(grid.size())) 
    {
        return false; // Hors limites
    }
    return grid[y][x] == 0; // Retourne vrai si c'est un chemin noir
}



Maze::~Maze() {}
