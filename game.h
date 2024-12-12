#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "boxer.h"
#include "player.h"

class Game {
private:
    sf::RenderWindow window;
    sf::Font font;
    sf::Texture boxerTexture;  
     sf::Sprite boxerSprite;
    bool fontLoaded;
    std::unique_ptr<Boxer> currentBoxer;
    Player player;
    std::vector<std::string> questions;
    int questionCount;

public:
    Game();
    void chooseBoxer();
    void displayQuestionAndCollectAnswer();
    void displayResponse(const std::string& response); 
    void handlePlayerReaction();
    void displayBoxerImage(const std::string &imagePath);
    void displayPunch();
    void displayHug();
    void play();
};

#endif 
