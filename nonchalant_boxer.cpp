#include "nonchalant_boxer.h"
#include <string>  
#include <map>    
#include <vector>  

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

std::string NonchalantBoxer::reactToResponse(const std::string& questionResponse, int playerResponseIndex) {
  
/*!
 * @brief dynamic response tree for nonchalant boxer

 */
    std::map<std::string, std::vector<std::string>> tailoredReactions = {
        {
            "Oh, I’m Chill Charlie. Just here for the vibes, you know?",
            {
                "Y'all vibe with that too? Cool, cool.",               // Player response 1
                "A drag? Hmm, maybe you’re the drag.",                 // Player response 2
                "You find vibes interesting? Guess that’s cool.",      // Player response 3
                "Back to boxing? Nah, I’m vibing just fine, thanks."   // Player response 4
            }
        },
        {
            "Not much, honestly. Looks cool though.",
            {
                "Nice, glad you think it’s cool too!",                                   // Player response 1
                "Yeah, I don’t know much, but what a drag, huh?",                       // Player response 2
                "What about what I said was interesting? What a drag.",                 // Player response 3
                "Thinking things are cool means I should get fired before getting hired? Whatever works, I guess." // Player response 4
            }
        },
        {
            "Being relaxed and not stressing out.",
            {
                "Cool, I see you value chilling out too.",                      // Player response 1
                "Wow? Yeah, stress is wild, man.",                              // Player response 2
                "Relaxing is interesting? Guess you need more chill in your life.", // Player response 3
                "Back to boxing? Stress-free life isn’t for everyone, I guess." // Player response 4
            }
        },
        {
            "Weakness? None. Perfection doesn’t crack.",
            {
                "Glad you get it. We’re on the same page.",                     // Player response 1
                "Drag? Nah, perfection's a vibe.",                              // Player response 2
                "Perfection's interesting? Guess I’ll take it.",                // Player response 3
                "Boxing? Sure, but I’ll still be perfect doing it.",            // Player response 4
            }
        },
        {
            "Because why not?",
            {
                "Exactly! Why not?",                                           
                "Wow, you’re really into deep analysis, huh?",                
                "Why not is interesting? Noted.",                               
                "Boxing? Nah, ‘why not’ works just fine here.",                
            }
        },
        {
            "Probably on a beach somewhere.",
            {
                "Nice, you’re into beach vibes too?",                         
                "What a drag? Beaches aren’t a drag.",                         
                "Interesting? Beaches are chill, man.",                        
                "Boxing? Nah, I’m headed for the beach.",                      
            }
        },
        {
            "It was too stressful. Not my vibe.",
            {
                "Cool, glad you get me.",                                     
                "Wow, stress really is the worst, huh?",                      
                "Stress is interesting? Not really.",                          
                "Boxing over stress? Hmm, makes sense to me.",                 
            }
        },
        {
            "Chilling out and keeping it easy.",
            {
                "That’s the way to go, right?",                                
                "Yeah, I get it, keeping it easy’s a drag for some.",          
                "Interesting? Guess you’re not used to chilling out.",          
                "Boxing’s easier? Sure, whatever you think.",                  
            }
        },
        {
            "Enough to keep me comfy.",
            {
                "Comfy vibes all around. Glad you agree.",                    
                "Wow? Comfy’s a vibe, man.",                                  
                "Interesting? Guess comfort’s a wild concept to you.",         
                "Boxing instead of comfy? Wild idea, but okay.",               
            }
        },
        {
            "Seems like a decent place.",
            {
                "Cool, glad you think so too.",                               
                "What a drag? Decent places aren’t drags.",                    
                "Interesting? I’ll take it as a compliment.",                  
                "Boxing instead of here? Sure, if that’s your vibe.",           
            }
        }
    };

    // Return the tailored reaction based on the boxer's initial response and player's reaction
    if (tailoredReactions.find(questionResponse) != tailoredReactions.end()) {
        return tailoredReactions[questionResponse][playerResponseIndex - 1];
    }

    return "Hmm, okay."; // Fallback nonchalant reaction
}