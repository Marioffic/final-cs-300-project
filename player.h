
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cassert>

class Player {
private:
    int health;

public:
    Player() : health(100) {}

    int getHealth() const { return health; }
    void decreaseHealth(int amount) {
        health -= amount;
        if (health < 0) health = 0;
    }
    void increaseHealth(int amount) {
        health += amount;
        if (health > 100) health = 100;
    }
};
