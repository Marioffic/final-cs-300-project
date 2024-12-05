#include <iostream>
#ifndef BOXER_H
#define BOXER_H
#define BOXER_H
#include <string>

class Boxer {
public:
    enum class Type { Angry, Nonchalant, Short };

    Boxer(const std::string& name, Type type, const std::string& punchType);

    const std::string& getName() const;
    Type getType() const;
    int getAngerMeter() const;
    int getAppreciationMeter() const;
    const std::string& getPunchType() const;

    virtual std::string respondToQuestion(const std::string& question) = 0;
    virtual std::string reactToResponse(int response) = 0;

    virtual ~Boxer() = default
protected:
    std::string name;
    Type type;
    int angerMeter;
    int appreciationMeter;
    std::string punchType;
};
#endif