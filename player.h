// player.h
#ifndef PLAYER_H
#define PLAYER_H

/*!
 * @class Player
 * @brief Represents the player in the Boxer Interview Game.
 * 
 * The Player class is responsible for maintaining the player's health and
 * providing methods to modify it during gameplay.
 */

class Player {
private:
    int health;
    /*!
     * @brief Constructs a Player object with default health.
     * 
     * Initializes the player's health to 100.
     */

public:
    Player() : health(100) {}  
    int getHealth() const { return health; }

    /*!
     * @brief Decreases the player's health by a specified amount.
     * 
     * Reduces the player's health by `amount`. If the resulting health
     * falls below 0, it is capped at 0.
     * 
     * @param amount The amount to decrease the health by.
     */
    
    void decreaseHealth(int amount) { health -= amount; if (health < 0) health = 0; }

    /*!
     * @brief Increases the player's health by a specified amount.
     * 
     * Increases the player's health by `amount`. If the resulting health
     * exceeds 100, it is capped at 100.
     * 
     * @param amount The amount to increase the health by.
     */

    void increaseHealth(int amount) { health += amount; if (health > 100) health = 100; }
};

#endif
