

#include <SFML/Graphics.hpp>
#include "Enemie.h"
#include "PacMan.h"  // Assurez-vous d'inclure la classe PacMan

int main() {
    // Dimensions de la fenêtre
    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;

    // Création de la fenêtre
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Labyrinthe avec Ennemis");
    window.setFramerateLimit(60); // Limiter la fréquence d'images

    // Création du labyrinthe
    Maze maze;

    // Création de Pac-Man
    PacMan pacMan("C:/Users/Dell/source/repos/Source/pacman.jpeg", 150.0f); // Remplacez par le chemin vers l'image de Pac-Man
    pacMan.setPosition(400.0f, 300.0f); // Position initiale de Pac-Man

    // Création des ennemis
    Enemie enemy("C:/Users/Dell/source/repos/Source/enemy1.png", 50.0f);
    enemy.setPosition(400.0f, 100.0f); // Position initiale de l'ennemi

    Enemie enemy1("C:/Users/Dell/source/repos/Source/enemy1.png", 50.0f);
    enemy1.setPosition(80.0f, 80.0f); // Position initiale de l'ennemi1

    Enemie enemy2("C:/Users/Dell/source/repos/Source/enemy1.png", 50.0f);
    enemy2.setPosition(500.0f, 500.0f);

    Enemie enemy3("C:/Users/Dell/source/repos/Source/enemy1.png", 50.0f);
    enemy3.setPosition(400.0f, 360.0f); // Position initiale de l'ennemi3

    // Liste des ennemis pour simplifier le code
    std::vector<Enemie*> enemies = { &enemy, &enemy1, &enemy2, &enemy3 };

    bool gameOver = false; // Variable pour gérer la fin du jeu
    float collisionThreshold = 40.0f; // Distance minimale pour considérer une collision

    // Charger la police pour afficher du texte
    sf::Font font;
    if (!font.loadFromFile("C:/Windows/Fonts/arial.ttf")) {  // Remplacer par le chemin vers la police existante
        std::cerr << "Erreur : Impossible de charger la police." << std::endl;
        return -1;
    }

    sf::Text gameOverText;
    gameOverText.setFont(font);
    gameOverText.setString("Game Over");
    gameOverText.setCharacterSize(50);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setPosition(WINDOW_WIDTH / 2 - gameOverText.getLocalBounds().width / 2, WINDOW_HEIGHT / 2 - gameOverText.getLocalBounds().height / 2);

    // Boucle principale
    sf::Clock clock; // Pour mesurer le temps entre les frames
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Si le jeu est terminé, on ne met pas à jour les ennemis et Pac-Man
        if (!gameOver) {
            // Récupérer les entrées clavier pour déplacer Pac-Man
            float deltaTime = clock.restart().asSeconds(); // Temps écoulé depuis la dernière frame
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                pacMan.moveUp(deltaTime);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                pacMan.moveDown(deltaTime);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                pacMan.moveLeft(deltaTime);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                pacMan.moveRight(deltaTime);
            }

            // Mise à jour des ennemis
            for (auto& e : enemies) {
                e->move(deltaTime, maze); // Déplacer l'ennemi
            }

            // Vérification des collisions entre Pac-Man et les ennemis
            for (auto& e : enemies) {
                if (e->checkCollision(pacMan)) { // Appel avec l'objet Pac-Man
                    gameOver = true;  // Collision détectée, fin du jeu
                    break;
                }
            }
        }

        // Dessin
        window.clear();
        maze.draw(window); // Dessiner le labyrinthe
        pacMan.draw(window); // Dessiner Pac-Man
        for (auto& e : enemies) {
            e->draw(window); // Dessiner les ennemis
        }

        // Afficher "Game Over" si le jeu est terminé
        if (gameOver) {
            window.draw(gameOverText);
        }

        window.display();
    }

    return 0;
}

