// AngryBoxer Implementation
#include "angry_boxer.h"

/*!
 * @brief Provides a response to a specific question.
 * 
 * This method returns a predefined response based on the question asked.
 * If the question is not recognized, a generic response is returned.
 * 
 * @param question The question being asked.
 * @return The boxer's response to the question.
 */

std::string AngryBoxer::respondToQuestion(const std::string& question) {
    if (question == "Tell me about yourself.") {
        return "I'm Angry Avery. Life's been a fight, literally and figuratively. Don't push me.";
    } else if (question == "What do you know about our company?") {
        return "I know you probably don’t deserve someone as good as me.";
    } else if (question == "What are your strengths?") {
        return "Strength? Punching people who annoy me.";
    } else if (question == "What are your weaknesses?") {
        return "Weakness? Only my trust in people who don’t deserve it.";
    } else if (question == "Why should we hire you?") {
        return "Because I’m the best. Next question.";
    } else if (question == "Where do you see yourself in five years?") {
        return "Alive, hopefully. That’s all.";
    } else if (question == "Why are you leaving your current job?") {
        return "Because they couldn’t handle my greatness.";
    } else if (question == "What motivates you?") {
        return "Anger. Lots of it.";
    } else if (question == "What are your salary expectations?") {
        return "More than you think I’m worth, because I am.";
    } else if (question == "Why do you want to work here?") {
        return "I don’t. You’re lucky I’m even here.";
    }
    return "I have no idea how to answer that.";
}
/*!
 * @brief Reacts to a player's response.
 * 
 * Based on the player's response, the AngryBoxer's anger or appreciation
 * meter is increased. The method returns the boxer's reaction to the player's input.
 * 
 * - Response 1 or 3 increases appreciation to 100 and returns a positive reaction.
 * - Response 2 increases anger to 100 and returns an aggressive reaction.
 * 
 * @param response The player's response (1, 2, or 3).
 * @return The boxer's reaction to the player's input.
 */

std::string AngryBoxer::reactToResponse(int response) {
    if (response == 2 || response == 2) {
        increaseAnger(100);
        return "What did you mean by that? Are you mocking me?";
    } else if (response == 1 || response == 3) {
        increaseAppreciation(100);
        return "Thanks. That means a lot.";
    }
    return "Hmm, okay.";
}