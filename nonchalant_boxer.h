#ifndef NONCHALANT_BOXER_H
#define NONCHALANT_BOXER_H

#include "boxer.h"

class NonchalantBoxer : public Boxer {
public:
 /*!
     * @brief Constructs a NonchalantBoxer object.
     * 
     * Initializes the NonchalantBoxer with the name "Chill Charlie", 
     * type `Nonchalant`, and the punch type "Jab".
     */

    NonchalantBoxer() : Boxer("Chill Charlie", Boxer::Type::Nonchalant, "Jab") {}
    std::string respondToQuestion(const std::string& question) override;
    /*!
     * @brief Reacts to a player's response.
     * 
     * Adjusts the boxer's anger or appreciation meter based on the player's response
     * and returns the boxer's reaction as a string.
     * 
     * @param response The player's response (1, 2, 3, or 4).
     * @return A string containing the boxer's reaction.
     */
    std::string reactToResponse(int response) override;
};

#endif