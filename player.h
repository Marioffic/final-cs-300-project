// player.h
#ifndef PLAYER_H
#define PLAYER_H

class Player {
private:
    int health;

public:
    Player() : health(100) {}  // Default health or whatever is appropriate
    int getHealth() const { return health; }
    void decreaseHealth(int amount) { health -= amount; if (health < 0) health = 0; }
    void increaseHealth(int amount) { health += amount; if (health > 100) health = 100; }
};

#endif
