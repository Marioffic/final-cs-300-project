CXX = g++
CXXFLAGS = -std=c++11 -I/opt/homebrew/Cellar/sfml/2.6.2/include
LDFLAGS = -L/opt/homebrew/Cellar/sfml/2.6.2/lib -lsfml-graphics -lsfml-window -lsfml-system
SOURCES = main.cpp game.cpp boxer.cpp angry_boxer.cpp nonchalant_boxer.cpp short_boxer.cpp player.cpp
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = app

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)
