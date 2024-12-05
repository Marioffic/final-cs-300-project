#ifndef SHORT_BOXER_H
#define SHORT_BOXER_H

#include "boxer.h"

class ShortBoxer : public Boxer {
public:
    ShortBoxer() : Boxer("Tiny Tim", Boxer::Type::Short, "Low Punch") {}
    std::string respondToQuestion(const std::string& question) override;
    std::string reactToResponse(int response) override;
};

#endif 