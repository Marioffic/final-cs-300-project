#include <iostream>
#ifndef BOXER_H
#define BOXER_H
#define BOXER_H
#include <string>

class Boxer {
public:
    enum class Type { Angry, Nonchalant, Short };

    Boxer(const std::string& name, Type type, const std::string& punchType);

    const std::string& getName() const { return name; }
    Type getType() const { return type; }
    int getAngerMeter() const { return angerMeter; }
    int getAppreciationMeter() const { return appreciationMeter; }
    const std::string& getPunchType() const { return punchType; }

    void increaseAnger(int amount);
    void increaseAppreciation(int amount);

private:
    std::string name;
    Type type;
    int angerMeter;
    int appreciationMeter;
    std::string punchType;
};
#endif