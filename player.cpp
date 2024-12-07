// game.h
#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "Boxer.h"
#include "Player.h" 
/*!
 * @class Game
 * @brief Manages the Boxer Interview Game.
 * 
 * The Game class handles the primary gameplay logic, including rendering the game window,
 * processing player interactions, and managing the flow of questions and responses.
 */
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
    
    /*!
     * @brief Displays the boxer selection menu.
     * 
     * Allows the player to choose a boxer from a predefined list and assigns the
     * selected boxer to `currentBoxer`.
     */
    void chooseBoxer();
    void render();
    void displayQuestionAndCollectAnswer();

     /*!
     * @brief Runs the main gameplay loop.
     * 
     * Handles the overall flow of the game, including the player's interaction
     * with boxers, asking questions, and managing rounds of interviews.
     */
    void play();
};

#endif 
