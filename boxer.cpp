/*!
 * @file boxer.cpp
 * @brief Implementation of the Boxer class.
 * 
 * This file contains the implementation of the Boxer class, which
 * defines the behavior and attributes of a boxer character in the game.
 */
#include "boxer.h"

/*!
 * @brief Constructs a Boxer object.
 * 
 * Initializes the boxer with a name, type, and punch type. Also sets
 * the initial anger and appreciation meters to 0.
 * 
 * @param name The name of the boxer.
 * @param type The type of the boxer (e.g., Angry, Nonchalant, Short).
 * @param punchType The specific punch type associated with the boxer.
 */

Boxer::Boxer(const std::string& name, Type type, const std::string& punchType)
    : name(name), type(type), angerMeter(0), appreciationMeter(0), punchType(punchType) {}

const std::string& Boxer::getName() const { return name; }
Boxer::Type Boxer::getType() const { return type; }
int Boxer::getAngerMeter() const { return angerMeter; }
int Boxer::getAppreciationMeter() const { return appreciationMeter; }

/*!
 * @brief Gets the name of the boxer.
 * 
 * @return A reference to the boxer's name.
 */

const std::string& Boxer::getPunchType() const { return punchType; }
/*!
 * @brief Increases the boxer's anger meter.
 * 
 * Adds the specified amount to the anger meter. If the resulting
 * value exceeds 100, the anger meter is capped at 100.
 * 
 * @param amount The amount to increase the anger meter by.
 */
void Boxer::increaseAnger(int amount) {
    angerMeter += amount;
    if (angerMeter > 100) angerMeter = 100;
}

/*!
 * @brief Gets the current appreciation meter value of the boxer.
 * 
 * @return The appreciation meter value.
 */
void Boxer::increaseAppreciation(int amount) {
    appreciationMeter += amount;
    if (appreciationMeter > 100) appreciationMeter = 100;
}
/*!
 * @brief Reacts to a player's response.
 * 
 * Based on the player's response, adjusts the anger or appreciation
 * meter and returns the boxer's reaction as a string.
 * 
 * @param response The player's response (1 to 4).
 * @return The boxer's reaction to the response.
 */
std::string Boxer::reactToResponse(int response) {
    switch (response) {
        case 1:
            increaseAppreciation(20);
            return "Thanks. That means a lot.";
        case 2:
            increaseAnger(30); // Wow, that was something, huh?
            return "What did you mean by that? Are you mocking me?";
        case 3:
            increaseAnger(50); // Sarcasm: Interesting...
            return "Are you trying to be funny? That's not cool.";
        case 4:
            increaseAnger(40); // Maybe go back to boxing?
            return "Go back to boxing? I'll show you boxing!";
        default:
            return "Hmm, okay.";
    }
}
