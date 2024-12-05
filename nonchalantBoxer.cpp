#include "nonchalant_boxer.h"

std::string NonchalantBoxer::respondToQuestion(const std::string& question) {
    if (question == "Tell me about yourself.") {
        return "Oh, I’m Chill Charlie. Just here for the vibes, you know?";
    } else if (question == "What do you know about our company?") {
        return "Not much, honestly. Looks cool though.";
    } else if (question == "What are your strengths?") {
        return "Being relaxed and not stressing out.";
    } else if (question == "What are your weaknesses?") {
        return "Weakness? None. Perfection doesn’t crack.";
    } else if (question == "Why should we hire you?") {
      return "Because why not?";
    } else if (question == "Where do you see yourself in five years?") {
        return "Probably on a beach somewhere.";
    } else if (question == "Why are you leaving your current job?") {
        return "It was too stressful. Not my vibe.";
    } else if (question == "What motivates you?") {
        return "Chilling out and keeping it easy.";
    } else if (question == "What are your salary expectations?") {
        return "Enough to keep me comfy.";
    } else if (question == "Why do you want to work here?") {
        return "Seems like a decent place.";
    }
    return "I have no idea how to answer that.";
}

std::string NonchalantBoxer::reactToResponse(int response) {
    if (response == 4) {
        increaseAnger(50);
        return "Wow, harsh. But okay, whatever.";
    } else if (response == 1 || response == 3) {
        increaseAppreciation(20);
        return "Thanks. That means a lot.";
    }
    return "Hmm, okay.";
}