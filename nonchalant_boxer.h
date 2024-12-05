#ifndef NONCHALANT_BOXER_H
#define NONCHALANT_BOXER_H

#include "boxer.h"

class NonchalantBoxer : public Boxer {
public:
    NonchalantBoxer() : Boxer("Chill Charlie", Boxer::Type::Nonchalant, "Jab") {}
    std::string respondToQuestion(const std::string& question) override;
    std::string reactToResponse(int response) override;
};

#endif