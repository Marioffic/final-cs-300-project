// game.h
#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "Boxer.h"
#include "Player.h" 

class Game {
private:
    sf::RenderWindow window;
    sf::Font font;
    bool fontLoaded;
    std::unique_ptr<Boxer> currentBoxer;
    Player player;  
    std::vector<std::string> questions;
    int questionCount;

public:
    Game();
    void chooseBoxer();
    void render();
    void displayQuestionAndCollectAnswer();
    void play();
};

#endif 
