#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Boxer {
public:
    enum Type { Angry, Nonchalant, Short };

private:
    std::string name;
    Type type;
    int angerMeter;
    int appreciationMeter;
    std::string punchType;
}