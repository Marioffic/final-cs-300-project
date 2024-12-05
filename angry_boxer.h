#ifndef ANGRY_BOXER_H
#define ANGRY_BOXER_H

#include "boxer.h"

class AngryBoxer : public Boxer {
public:
    AngryBoxer() : Boxer("Angry Avery", Boxer::Type::Angry, "Uppercut") {}
    std::string respondToQuestion(const std::string& question) override;
    std::string reactToResponse(int response) override;
};

#endif 