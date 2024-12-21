#include "Enemie.h"
#include <iostream>
#include <cmath> // Pour std::floor

// Constructeur
Enemie::Enemie(const std::string& textureFile, float initSpeed): direction(0), movementTimer(0) 
{
    if (!texture.loadFromFile(textureFile)) {
        std::cerr << "Erreur de chargement de la texture de l'ennemi!" << std::endl;
    }
    sprite.setTexture(texture);
    speed = initSpeed;
}

// Méthode pour positionner l'ennemi
void Enemie::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}

// Méthode pour obtenir la position de l'ennemi
sf::Vector2f Enemie::getPosition() const {
    return sprite.getPosition();
}

// Méthode pour déplacer l'ennemi
void Enemie::move(float deltaTime, const Maze& maze) {
    // Conversion de la position de l'ennemi en coordonnées de grille
    sf::Vector2f position = sprite.getPosition();

    //pour obtenir l'indice de la grill associe
    int gridX = std::floor(position.x / TILE_SIZE);
    int gridY = std::floor(position.y / TILE_SIZE);

    // Incrémente le timer
    movementTimer += deltaTime;

    // Se déplacer uniquement après un certain intervalle
    if (movementTimer >= 0.5f) { // 0.5s entre les mouvements
        movementTimer = 0; // Réinitialiser le timer

        // Calcul de la nouvelle position en fonction de la direction actuelle
        int newGridX = gridX, newGridY = gridY;
        switch (direction) {
        case 0: // Gauche
            newGridX -= 1;
            break;
        case 1: // Droite
            newGridX += 1;
            break;
        case 2: // Haut
            newGridY += 1;
            break;
        case 3: // Haut
            newGridY -= 1;
            break;
        }

        // Vérification si le déplacement est valide
        if (maze.isPath(newGridX, newGridY)) {
            // Appliquer le mouvement
            sprite.setPosition(newGridX * TILE_SIZE, newGridY * TILE_SIZE);
        }
        // Passer à la direction suivante (0 -> 1 -> 2 -> 3)
        direction = (direction + 1) % 4;
        
    }
}


// Méthode pour dessiner l'ennemi
void Enemie::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

bool Enemie::checkCollision(const PacMan& pacMan) const 
{
    // Récupérer la position de Pac-Man
    sf::Vector2f pacPosition = pacMan.getPosition();

    // Récupérer la position de l'ennemi
    sf::Vector2f enemyPosition = sprite.getPosition();

    // Vérifier si les positions se chevauchent
    return std::abs(pacPosition.x - enemyPosition.x) < TILE_SIZE &&
        std::abs(pacPosition.y - enemyPosition.y) < TILE_SIZE;
}


// Méthode pour tuer l'ennemi (réinitialisation de sa position)
void Enemie::die() {
    //sprite.setPosition(-100, -100); // Déplace l'ennemi en dehors de l'écran
}
