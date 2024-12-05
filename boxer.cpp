#include "Boxer.h"

Boxer::Boxer(const std::string& name, Type type, const std::string& punchType)
    : name(name), type(type), angerMeter(0), appreciationMeter(0), punchType(punchType) {}

const std::string& Boxer::getName() const { return name; }
Boxer::Type Boxer::getType() const { return type; }
int Boxer::getAngerMeter() const { return angerMeter; }
int Boxer::getAppreciationMeter() const { return appreciationMeter; }
const std::string& Boxer::getPunchType() const { return punchType; }

void Boxer::increaseAnger(int amount) {
    angerMeter += amount;
    if (angerMeter > 100) angerMeter = 100;
}

void Boxer::increaseAppreciation(int amount) {
    appreciationMeter += amount;
    if (appreciationMeter > 100) appreciationMeter = 100;
}