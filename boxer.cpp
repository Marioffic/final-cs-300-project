#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Boxer {
public:
    enum Type { Angry, Nonchalant, Short };

private:
    std::string name;
    Type type;
    int angerMeter;
    int appreciationMeter;
    std::string punchType;
public:
    Boxer(const std::string& name, Type type, const std::string& punchType)
        : name(name), type(type), angerMeter(0), appreciationMeter(0), punchType(punchType) {}

    const std::string& getName() const { return name; }
    Type getType() const { return type; }
    int getAngerMeter() const { return angerMeter; }
    int getAppreciationMeter() const { return appreciationMeter; }
    const std::string& getPunchType() const { return punchType; }

    void increaseAnger(int amount) {
        angerMeter += amount;
        if (angerMeter > 100) angerMeter = 100;
    }

    void increaseAppreciation(int amount) {
        appreciationMeter += amount;
        if (appreciationMeter > 100) appreciationMeter = 100;
    }
};