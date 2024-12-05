#include "game.h"
#include "angry_boxer.h"
#include "nonchalant_boxer.h"
#include "short_boxer.h"
#include "game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <memory>

namespace std {
    template <typename T, typename... Args>
    std::unique_ptr<T> make_unique(Args&&... args) {
        return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
    }
}


Game::Game() : window(sf::VideoMode(800, 600), "Boxer Interview Game"), questions({
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
}) {}


void Game::render() {
    window.clear();
    window.display();
}

void Game::chooseBoxer() {
    std::vector<std::unique_ptr<Boxer>> boxers;
    boxers.emplace_back(std::make_unique<AngryBoxer>());
    boxers.emplace_back(std::make_unique<NonchalantBoxer>());
    boxers.emplace_back(std::make_unique<ShortBoxer>());

    std::cout << "Choose your boxer:\n";
    for (size_t i = 0; i < boxers.size(); ++i) {
        std::cout << i + 1 << ". " << boxers[i]->getName() << "\n";
    }

    int choice;
    std::cin >> choice;
    
     boxers[choice - 1].release();

    std::cout << "You chose " << currentBoxer->getName() << "!\n";
}

void Game::play() {
    chooseBoxer();

    while (player.getHealth() > 0) {
        std::cout << "Ask a question:\n";
        for (size_t i = 0; i < questions.size(); ++i) {
            std::cout << i + 1 << ". " << questions[i] << "\n";
        }
         int questionIndex;
        std::cin >> questionIndex;
        --questionIndex;

        std::cout << currentBoxer->getName() << " responds: ... "
        << currentBoxer->respondToQuestion(questions[questionIndex]) << "\n";

        std::cout << "Choose your response:\n"
                  << "1. Good answer, you’ll fit right in here\n"
                  << "2. Wow, that was something huh?\n"
                  << "3. Interesting...\n"
                  << "4. Maybe go back to boxing?\n";

        int response;
        std::cin >> response;

        std::cout << currentBoxer->reactToResponse(response) << "\n";

        if (response == 1 || response == 3) {
            currentBoxer->increaseAppreciation(20);
            std::cout << "The boxer seems happier.\n";
        } else {
            currentBoxer->increaseAnger(20);
            std::cout << "The boxer seems angrier!\n";
        }

        if (currentBoxer->getAngerMeter() >= 100) {
            std::cout << currentBoxer->getName() << " punches you!\n";
            player.decreaseHealth(rand() % 36 + 15);
            std::cout << "Your health is now " << player.getHealth() << "\n";
        }

        if (currentBoxer->getAppreciationMeter() >= 100) {
            std::cout << currentBoxer->getName() << " gives you a hug!\n";
            player.increaseHealth(20);
            std::cout << "Your health is now " << player.getHealth() << "\n";
        }

        render();
    }

    std::cout << "Game over!\n";
}
