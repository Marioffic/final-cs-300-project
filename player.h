#ifndef PLAYER_H
#define PLAYER_H

class Player {
private:
    int health;

public:
    Player();

    int getHealth() const;
    void decreaseHealth(int amount);
    void increaseHealth(int amount);
};

#endif