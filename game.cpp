#include "game.h"
#include "angry_boxer.h"
#include "nonchalant_boxer.h"
#include "short_boxer.h"
#include <iostream>

// Constructor
Game::Game() : window(sf::VideoMode(800, 600), "Boxer Interview Game"), questionCount(0), fontLoaded(false), questions({
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
}) {
    if (!font.loadFromFile("Roboto-Black.ttf")) {
        std::cerr << "Failed to load font!\n";
    } else {
        fontLoaded = true;
    }
}

// Display the boxer selection screen
void Game::chooseBoxer() {
    sf::Text boxerText;
    boxerText.setFont(font);
    boxerText.setCharacterSize(24);
    boxerText.setFillColor(sf::Color::White);
    boxerText.setStyle(sf::Text::Bold);

    std::vector<std::string> boxers = {"Angry Avery", "Chill Charlie", "Tiny Tim"};

    while (window.isOpen()) {
        window.clear(sf::Color::Black);

        for (size_t i = 0; i < boxers.size(); ++i) {
            boxerText.setString(std::to_string(i + 1) + ". " + boxers[i]);
            boxerText.setPosition(50.f, i * 50.f + 100.f);
            window.draw(boxerText);
        }

        window.display();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return;
            }

             if (event.type == sf::Event::KeyPressed) {
                int choice = event.key.code - sf::Keyboard::Num1;
                if (choice == 0) {
                    currentBoxer = std::unique_ptr<AngryBoxer>(new AngryBoxer());
                } else if (choice == 1) {
                    currentBoxer = std::unique_ptr<NonchalantBoxer>(new NonchalantBoxer());
                } else if (choice == 2) {
                    currentBoxer = std::unique_ptr<ShortBoxer>(new ShortBoxer());
                }
                    std::cout << "You chose " << currentBoxer->getName() << "!\n";
                    return;
                }
            }
        }
}


void Game::displayQuestionAndCollectAnswer() {
    if (!fontLoaded) return;

    sf::Text questionText;
    questionText.setFont(font);
    questionText.setCharacterSize(24);
    questionText.setFillColor(sf::Color::White);
    questionText.setStyle(sf::Text::Bold);

    sf::Text responseText;
    responseText.setFont(font);
    responseText.setCharacterSize(20);
    responseText.setFillColor(sf::Color::Yellow);
    responseText.setStyle(sf::Text::Italic);

    while (window.isOpen()) {
        window.clear(sf::Color::Black);

 
        for (size_t i = 0; i < questions.size(); ++i) {
            questionText.setString(std::to_string(i + 1) + ". " + questions[i]);
            questionText.setPosition(50.f, i * 30.f + 50.f);
            window.draw(questionText);
        }

        window.display();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return;
            }

            if (event.type == sf::Event::KeyPressed) {
                int questionIndex = event.key.code - sf::Keyboard::Num1;
                if (questionIndex >= 0 && questionIndex < static_cast<int>(questions.size())) {
                    // Display the boxer's response
                    std::string response = currentBoxer->respondToQuestion(questions[questionIndex]);
                    displayResponse(response);

                    // Display response choices
                    std::vector<std::string> responses = {
                        "1. Good answer, you'll fit right in here.",
                        "2. Wow, that was something, huh?",
                        "3. Interesting...",
                        "4. Maybe go back to boxing?"
                    };

                    while (window.isOpen()) {
                        window.clear(sf::Color::Black);

                        for (size_t i = 0; i < responses.size(); ++i) {
                            responseText.setString(responses[i]);
                            responseText.setPosition(50.f, i * 30.f + 300.f);
                            window.draw(responseText);
                        }

                        window.display();

                        sf::Event responseEvent;
                        while (window.pollEvent(responseEvent)) {
                            if (responseEvent.type == sf::Event::Closed) {
                                window.close();
                                return;
                            }

                            if (responseEvent.type == sf::Event::KeyPressed) {
                                int responseIndex = responseEvent.key.code - sf::Keyboard::Num1;
                                if (responseIndex >= 0 && responseIndex < static_cast<int>(responses.size())) {
                                    // React to the player's response
                                    std::string boxerReaction = currentBoxer->reactToResponse(responseIndex + 1);
                                    displayResponse(boxerReaction);
                                    return; 
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}


void Game::handlePlayerReaction() {
    sf::Text responseText;
    responseText.setFont(font);
    responseText.setCharacterSize(20);
    responseText.setFillColor(sf::Color::Yellow);
    responseText.setStyle(sf::Text::Italic);

    std::vector<std::string> responses = {
        "1. Good answer, you'll fit right in here.",
        "2. Wow, that was something, huh?",
        "3. Interesting...",
        "4. Maybe go back to boxing?"
    };

    while (window.isOpen()) {
        window.clear(sf::Color::Black);

        // Display response options
        for (size_t i = 0; i < responses.size(); ++i) {
            responseText.setString(responses[i]);
            responseText.setPosition(50.f, i * 30.f + 300.f);
            window.draw(responseText);
        }

        window.display();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return;
            }

            if (event.type == sf::Event::KeyPressed) {
                int responseIndex = event.key.code - sf::Keyboard::Num1;
                if (responseIndex >= 0 && responseIndex < static_cast<int>(responses.size())) {
                    // React to the player's response
                    std::string boxerReaction = currentBoxer->reactToResponse(responseIndex + 1);

                    // Handle punch or hug based on anger or appreciation
                    if (currentBoxer->getAngerMeter() >= 100) {
                        displayPunch();
                    } else if (currentBoxer->getAppreciationMeter() >= 100) {
                        displayHug();
                    } else {
                        displayResponse(boxerReaction);
                    }
                    return; 
                }
            }
        }
    }
}

// Display the "you've been hugged" message
void Game::displayHug() {
    sf::Text hugText;
    hugText.setFont(font);
    hugText.setCharacterSize(32);
    hugText.setFillColor(sf::Color::Green);
    hugText.setStyle(sf::Text::Bold);
    hugText.setString("YOU'VE BEEN HUGGED!");
    hugText.setPosition(100.f, 300.f);

    window.clear(sf::Color::Black);
    window.draw(hugText);
    window.display();

    sf::Clock clock;
    while (clock.getElapsedTime().asSeconds() < 3.0f) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return;
            }
        }
    }
}

// Display the "you've been punched" message
void Game::displayPunch() {
    sf::Texture punchTexture;
    if (!punchTexture.loadFromFile("punch.png")) {
        std::cerr << "Failed to load punch image!\n";
        return;
    }

    sf::Sprite punchSprite(punchTexture);
    punchSprite.setPosition(200.f, 200.f);

    sf::Text punchText;
    punchText.setFont(font);
    punchText.setCharacterSize(32);
    punchText.setFillColor(sf::Color::Red);
    punchText.setStyle(sf::Text::Bold);
    punchText.setString("YOU'VE BEEN PUNCHED!");
    punchText.setPosition(100.f, 450.f);

    window.clear(sf::Color::Black);
    window.draw(punchSprite);
    window.draw(punchText);
    window.display();

    sf::Clock clock;
    while (clock.getElapsedTime().asSeconds() < 3.0f) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return;
            }
        }
    }
}

// Display the boxer's response
void Game::displayResponse(const std::string& response) {
    sf::Text responseText;
    responseText.setFont(font);
    responseText.setCharacterSize(24);
    responseText.setFillColor(sf::Color::Yellow);
    responseText.setStyle(sf::Text::Bold);
    responseText.setString(response);
    responseText.setPosition(50.f, 300.f);

    window.clear(sf::Color::Black);
    window.draw(responseText);
    window.display();

    sf::Clock clock;
    while (clock.getElapsedTime().asSeconds() < 3.0f) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return;
            }
        }
    }
}




// Main game loop
void Game::play() {
    if (!fontLoaded) {
        std::cerr << "Font not loaded, cannot play the game.\n";
        return;
    }

    while (window.isOpen()) {
        chooseBoxer(); 
        questionCount = 0;

        while (player.getHealth() > 0) {
            displayQuestionAndCollectAnswer();
            questionCount++;

            // If 10 questions have been asked, prompt for another interview
            if (questionCount >= static_cast<int>(questions.size())) {
                std::cout << "Would you like to interview another boxer? (yes/no)\n";
                std::string answer;
                std::cin >> answer;

                if (answer == "yes") {
                    break; 
                } else {
                    window.close(); 
                    return;
                }
            }
        }

        if (!window.isOpen()) {
            break; 
        }
    }

    std::cout << "Game over!\n";
}
