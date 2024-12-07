#include "short_boxer.h"

std::string ShortBoxer::respondToQuestion(const std::string& question) {
    if (question == "Tell me about yourself.") {
        return "I'm Tiny Tim, small but mighty. Don’t let the height fool you.";
    } else if (question == "What do you know about our company?") {
        return "I know enough to make an impact.";
    } else if (question == "What are your strengths?") {
        return "Speed, agility, and a low center of gravity.";
    } else if (question == "What are your weaknesses?") {
        return "Weakness? Maybe I can't reach the top shelf, but that’s what ladders are for.";
    } else if (question == "Why should we hire you?") {
        return "Because I’ll outwork everyone else here.";
    } else if (question == "Where do you see yourself in five years?") {
        return "Hopefully taller, but still winning.";
    } else if (question == "Why are you leaving your current job?") {
        return "It was a stepping stone. I’m aiming higher.";
    } else if (question == "What motivates you?") {
        return "Proving people wrong.";
    } else if (question == "What are your salary expectations?") {
        return "Enough to show I’m valued.";
    } else if (question == "Why do you want to work here?") {
        return "Because this is the place to prove myself.";
    }
    return "I have no idea how to answer that.";
}

std::string ShortBoxer::reactToResponse(int response) {
    if (response == 4 || response == 2) {
        increaseAnger(100);
        return "Go back to boxing? I’m still punching above my weight here.";
    } else if (response == 1 || response == 3) {
        increaseAppreciation(100);
        return "Thanks. That means a lot.";
    }
    return "Hmm, okay.";
}
