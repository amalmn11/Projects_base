/*#include <iostream>
#include <string>

class Move {
public:
    std::string choice;

    void setChoice(const std::string& choice) {
        this->choice = choice;
    }

    std::string getChoice() const {
        return choice;
    }
};

class Player {
private:
    std::string name;
    Move move;

public:
    Player(const std::string& name) : name(name) {}

    void setMove(const Move& move) {
        this->move = move;
    }

    Move getMove() const {
        return move;
    }

    std::string getName() const {
        return name;
    }
};

class Game {
private:
    Player* player1;
    Player* player2;

public:
    Game(Player* p1, Player* p2) : player1(p1), player2(p2) {}

    void playRound() {
        std::string choice1, choice2;
        std::cout << player1->getName() << ", choisissez (pierre, papier, ciseaux): ";
        std::cin >> choice1;
        player1->setMove(Move{ choice1 });

        std::cout << player2->getName() << ", choisissez (pierre, papier, ciseaux): ";
        std::cin >> choice2;
        player2->setMove(Move{ choice2 });

        determineWinner();
    }

    void determineWinner() {
        std::string choice1 = player1->getMove().getChoice();
        std::string choice2 = player2->getMove().getChoice();

        if (choice1 == choice2) {
            std::cout << "Egalité !\n";
        }
        else if ((choice1 == "pierre" && choice2 == "ciseaux") ||
            (choice1 == "papier" && choice2 == "pierre") ||
            (choice1 == "ciseaux" && choice2 == "papier")) {
            std::cout << player1->getName() << " gagne !\n";
        }
        else {
            std::cout << player2->getName() << " gagne !\n";
        }
    }
};

int main() {
    Player player1("Joueur 1");
    Player player2("Joueur 2");

    Game game(&player1, &player2);

    bool keepPlaying = true;
    while (keepPlaying) {
        game.playRound(); // Lancer un round du jeu

        char choice;
        std::cout << "Voulez-vous jouer à nouveau ? (o = oui, n = non): ";
        std::cin >> choice;

        if (choice != 'o' && choice != 'O') {
            keepPlaying = false; // Si l'utilisateur choisit autre chose que 'o', arrêter la boucle
        }
    }

    std::cout << "Merci d'avoir joué !\n";
    return 0;
}
*/



#include <iostream>
#include <conio.h> // Pour _kbhit() et _getch()
#include <vector>
#include <cstdlib> // Pour rand() et srand()
#include <ctime>   // Pour initialiser srand()

using namespace std;

// Classe de base pour les objets du jeu
class GameObject {
protected:
    int x, y;

public:
    GameObject(int x = 0, int y = 0) : x(x), y(y) {}
    int getX() const { return x; }
    int getY() const { return y; }
    void setPosition(int newX, int newY) {
        x = newX;
        y = newY;
    }
};

// Classe pour la nourriture, hérite de GameObject
class Food : public GameObject {
public:
    Food(int x = 0, int y = 0) : GameObject(x, y) {}
    void generateNewPosition(int maxWidth, int maxHeight) {
        x = rand() % maxWidth;
        y = rand() % maxHeight;
    }
};

// Classe pour le serpent
class Snake : public GameObject {
private:
    vector<pair<int, int>> body; // Corps du serpent (liste des segments)
    int dx, dy;                  // Direction du mouvement

public:
    Snake(int startX, int startY) : GameObject(startX, startY), dx(1), dy(0) {
        body.push_back({ x, y });
    }

    void move() {
        x += dx;
        y += dy;
        body.push_back({ x, y });
        body.erase(body.begin());
    }

    void grow() {
        body.push_back({ x, y });
    }

    void changeDirection(char input) {
        switch (input) {
        case 'w': if (dy == 0) { dx = 0; dy = -1; } break; // Haut
        case 's': if (dy == 0) { dx = 0; dy = 1; } break;  // Bas
        case 'a': if (dx == 0) { dx = -1; dy = 0; } break; // Gauche
        case 'd': if (dx == 0) { dx = 1; dy = 0; } break;  // Droite
        }
    }

    bool checkCollision(int maxWidth, int maxHeight) {
        // Collision avec les murs
        if (x < 0 || y < 0 || x >= maxWidth || y >= maxHeight) return true;

        // Collision avec le corps
        for (size_t i = 0; i < body.size() - 1; i++) {
            if (body[i].first == x && body[i].second == y) return true;
        }
        return false;
    }

    bool eatFood(Food& food) {
        return x == food.getX() && y == food.getY();
    }

    void render() const {
        for (const auto& segment : body) {
            cout << "\033[" << segment.second + 1 << ";" << segment.first + 1 << "H" << "O";
        }
    }
};

// Classe pour le jeu
class Game {
private:
    int width, height;
    Snake snake;
    Food food;
    bool gameOver;

public:
    Game(int w, int h) : width(w), height(h), snake(w / 2, h / 2), food(rand() % w, rand() % h), gameOver(false) {}

    void run() {
        while (!gameOver) {
            render();
            input();
            logic();
            //_sleep(100); // Vitesse du jeu
        }
        cout << "Game Over! Score: " << snake.getX() << "\n";
    }

    void render() {
        system("cls");
        // Bordure
        for (int i = 0; i < width + 2; i++) cout << "#";
        cout << endl;
        for (int i = 0; i < height; i++) {
            cout << "#";
            for (int j = 0; j < width; j++) {
                if (food.getX() == j && food.getY() == i)
                    cout << "F";
                else
                    cout << " ";
            }
            cout << "#\n";
        }
        for (int i = 0; i < width + 2; i++) cout << "#";
        cout << endl;

        // Afficher le serpent
        snake.render();
    }

    void input() {
        if (_kbhit()) {
            char key = _getch();
            snake.changeDirection(key);
        }
    }

    void logic() {
        snake.move();
        if (snake.eatFood(food)) {
            snake.grow();
            food.generateNewPosition(width, height);
        }
        if (snake.checkCollision(width, height)) {
            gameOver = true;
        }
    }
};

// Point d'entrée
int main() {
    srand((unsigned int)time(0)); // Initialiser les nombres aléatoires
    Game game(20, 20); // Créer une partie de 20x10
    game.run();
    return 0;
}
