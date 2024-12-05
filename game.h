#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Boxer.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Game {
private:
    Player player;
    Boxer* currentBoxer;
    std::vector<std::string> questions;
    sf::RenderWindow window;

    oid initializeQuestions();
    void render();

    public:
    Game();
    void chooseBoxer();
    void play();
};

#endif 