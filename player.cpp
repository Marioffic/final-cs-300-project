
#include "player.h"

    Player::Player() : health(100) {};

    int Player::getHealth() const { return health; }
    void Player::decreaseHealth(int amount) {
        health -= amount;
        if (health < 0) health = 0;
    }
    void Player::increaseHealth(int amount) {
        health += amount;
        if (health > 100) health = 100;
    }


