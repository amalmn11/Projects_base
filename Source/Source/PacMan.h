#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class PacMan
{
private:
    sf::Sprite sprite;   // L'image de Pac-Man
    sf::Texture texture;  // La texture de Pac-Man
    float speed;          // Vitesse de d?placement de Pac-Man

public:
    // Constructeur
    PacMan(const std::string& textureFile, float initSpeed);


    // M?thode pour positionner Pac-Man
    void setPosition(float x, float y);


    // M?thodes pour d?placer Pac-Man
    void moveUp(float deltaTime);


    void moveDown(float deltaTime);



    void moveLeft(float deltaTime);



    void moveRight(float deltaTime);


    // M?thode pour dessiner Pac-Man
    void draw(sf::RenderWindow& window);

    sf::Vector2f getPosition() const;





};

