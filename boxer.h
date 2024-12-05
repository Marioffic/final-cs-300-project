#include <iostream>
#define BOXER_H
#define BOXER_H
#include <string>

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

     void increaseAnger(int amount);
    void increaseAppreciation(int amount);
};
