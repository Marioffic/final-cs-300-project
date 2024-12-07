#include "boxer.h"

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
