#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Maze.h" 
#include "PacMan.h"


class Enemie {
private:
    static const int TILE_SIZE = 40;
    sf::Sprite sprite;   // L'image de l'ennemi
    sf::Texture texture; // La texture de l'ennemi
    float speed;         // Vitesse de déplacement de l'ennemi
    int direction;       // indique dans quel direction l'ennemi se deplace  (0: gauche, 1: droite, 2: haut, 3: Bas)
    float movementTimer; // Timer pour contrôler le rythme du mouvement

public:
    // Constructeur
    Enemie(const std::string& textureFile, float initSpeed);

    // Méthode pour positionner l'ennemi
    void setPosition(float x, float y);

    // Méthode pour obtenir la position de l'ennemi
    sf::Vector2f getPosition() const;

    // Méthode pour déplacer l'ennemi
    void move(float deltaTime, const Maze& maze);

    // Méthode pour dessiner l'ennemi
    void draw(sf::RenderWindow& window);

    //tester la collisione entre enemie et pacman
    bool checkCollision(const PacMan& pacMan) const;

    // Méthode pour tuer l'ennemi (réinitialisation de sa position)
    void die();
};
