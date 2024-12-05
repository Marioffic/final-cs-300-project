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

    void initializeQuestions() {
        questions = {
            "Tell me about yourself.",
            "What do you know about our company?",
            "What are your strengths?",
            "What are your weaknesses?",
            "Why should we hire you?",
            "Where do you see yourself in five years?",
            "Why are you leaving your current job?",
            "What motivates you?",
            "What are your salary expectations?",
            "Why do you want to work here?"
        };
    }
};