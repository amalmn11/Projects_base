#include "PacMan.h"

PacMan::PacMan(const std::string& textureFile, float initSpeed)
{
    if (!texture.loadFromFile(textureFile)) {
        std::cerr << "Erreur : Impossible de charger l'image de Pac-Man" << std::endl;
        exit(-1);
    }
    sprite.setTexture(texture);
    speed = initSpeed;

}


void PacMan::setPosition(float x, float y)
{
    sprite.setPosition(x, y);
}

// M�thodes pour d�placer Pac-Man
void PacMan::moveUp(float deltaTime) {
    sprite.move(0, -speed * deltaTime);  // D�placer vers le haut
}

void PacMan::moveDown(float deltaTime) {
    sprite.move(0, speed * deltaTime);   // D�placer vers le bas
}

void PacMan::moveLeft(float deltaTime) {
    sprite.move(-speed * deltaTime, 0);  // D�placer vers la gauche
}

void PacMan::moveRight(float deltaTime) {
    sprite.move(speed * deltaTime, 0);   // D�placer vers la droite
}

// M�thode pour dessiner Pac-Man
void PacMan::draw(sf::RenderWindow& window) {
    window.draw(sprite);  // Dessiner Pac-Man dans la fen�tre
}

sf::Vector2f PacMan::getPosition() const
{
    return sprite.getPosition();
}

