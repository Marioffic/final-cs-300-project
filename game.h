#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "boxer.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Game {
private:
    Player player;
    Boxer* currentBoxer;
    std::vector<std::string> questions;
    sf::RenderWindow window;

    void initializeQuestions();
    void render();

    public:
        Game();
        void chooseBoxer();
        void play();
};

#endif 