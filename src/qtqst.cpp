#include <SFML/Graphics.hpp>

#include "AnimatedSprite.hpp"

#include "inputhandler.hpp"
#include "level.hpp"

double secondsPerTick = 0.5;

Level* currentLevel;

int main() {
  
  sf::RenderWindow window(sf::VideoMode(640, 480), "qtqst under construction");
  
  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);

  sf::Clock clock;

  InputHandler handler(window, shape);

  while (window.isOpen()) {
      
    sf::Event event;
        
    while (window.pollEvent(event)) {
          
      handler.handleInput(event);
    }

    sf::Time dt = clock.restart();

    //currentLevel.updateGameLogic(dt * secondsPerTick);

    //currentLevel.updateRendition(dt);
    
    window.clear();
    window.draw(shape);
    window.display();
  }

  return 0;
}
