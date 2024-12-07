#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include "player.h"
#include "angry_boxer.h"
#include "nonchalant_boxer.h"
#include "short_boxer.h"
#include "game.h"

// 1. Player Tests
TEST_CASE("Player health initializes correctly", "[Player]") {
    Player player;
    REQUIRE(player.getHealth() == 100);
}

TEST_CASE("Player health decreases correctly", "[Player]") {
    Player player;
    player.decreaseHealth(30);
    REQUIRE(player.getHealth() == 70);
    player.decreaseHealth(80); // Should not go below 0
    REQUIRE(player.getHealth() == 0);
}

TEST_CASE("Player health increases correctly", "[Player]") {
    Player player;
    player.decreaseHealth(50);
    player.increaseHealth(30);
    REQUIRE(player.getHealth() == 80);
    player.increaseHealth(50); // Should not exceed 100
    REQUIRE(player.getHealth() == 100);
}

// 2. AngryBoxer Tests
TEST_CASE("AngryBoxer responds to questions correctly", "[AngryBoxer]") {
    AngryBoxer boxer;
    REQUIRE(boxer.respondToQuestion("Tell me about yourself.") == "I'm Angry Avery. Life's been a fight, literally and figuratively. Don't push me.");
    REQUIRE(boxer.respondToQuestion("What motivates you?") == "Anger. Lots of it.");
    REQUIRE(boxer.respondToQuestion("Unknown question") == "I have no idea how to answer that.");
}

TEST_CASE("AngryBoxer reacts to player responses correctly", "[AngryBoxer]") {
    AngryBoxer boxer;
    REQUIRE(boxer.reactToResponse(1) == "Thanks. That means a lot.");
    REQUIRE(boxer.reactToResponse(2) == "What did you mean by that? Are you mocking me?");
    REQUIRE(boxer.reactToResponse(3) == "Thanks. That means a lot.");
    REQUIRE(boxer.reactToResponse(4) == "Hmm, okay.");
}

TEST_CASE("AngryBoxer anger and appreciation meters adjust correctly", "[AngryBoxer]") {
    AngryBoxer boxer;
    boxer.reactToResponse(2); // Anger increases by 100
    REQUIRE(boxer.getAngerMeter() == 100);
    boxer.reactToResponse(1); // Appreciation increases by 100
    REQUIRE(boxer.getAppreciationMeter() == 100);
}

// 3. NonchalantBoxer Tests
TEST_CASE("NonchalantBoxer responds to questions correctly", "[NonchalantBoxer]") {
    NonchalantBoxer boxer;
    REQUIRE(boxer.respondToQuestion("Tell me about yourself.") == "Oh, I’m Chill Charlie. Just here for the vibes, you know?");
    REQUIRE(boxer.respondToQuestion("What motivates you?") == "Chilling out and keeping it easy.");
    REQUIRE(boxer.respondToQuestion("Unknown question") == "I have no idea how to answer that.");
}

TEST_CASE("NonchalantBoxer reacts to player responses correctly", "[NonchalantBoxer]") {
    NonchalantBoxer boxer;
    REQUIRE(boxer.reactToResponse(1) == "Thanks. That means a lot.");
    REQUIRE(boxer.reactToResponse(4) == "Wow, harsh. But okay, whatever.");
}

// 4. ShortBoxer Tests
TEST_CASE("ShortBoxer responds to questions correctly", "[ShortBoxer]") {
    ShortBoxer boxer;
    REQUIRE(boxer.respondToQuestion("Tell me about yourself.") == "I'm Tiny Tim, small but mighty. Don’t let the height fool you.");
    REQUIRE(boxer.respondToQuestion("What are your strengths?") == "Speed, agility, and a low center of gravity.");
    REQUIRE(boxer.respondToQuestion("Unknown question") == "I have no idea how to answer that.");
}

TEST_CASE("ShortBoxer reacts to player responses correctly", "[ShortBoxer]") {
    ShortBoxer boxer;
    REQUIRE(boxer.reactToResponse(1) == "Thanks. That means a lot.");
    REQUIRE(boxer.reactToResponse(2) == "Go back to boxing? I’m still punching above my weight here.");
}

// 5. Game Tests
TEST_CASE("Game initializes correctly", "[Game]") {
    Game game;
    REQUIRE(game.play); // Ensure the game object initializes without crashing
}

TEST_CASE("Game allows boxer selection", "[Game]") {
    Game game;
    game.chooseBoxer();
    REQUIRE(game.play);
}

TEST_CASE("Game processes questions and responses", "[Game]") {
    Game game;
    game.displayQuestionAndCollectAnswer();
    REQUIRE(game.play);
}
