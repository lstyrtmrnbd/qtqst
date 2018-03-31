#include <SFML/Graphics.hpp>

#include "AnimatedSprite.hpp"

#include "inputhandler.hpp"
#include "level.hpp"
#include "levelpainter.hpp"

double secondsPerTick = 0.5;

Level* currentLevel;

int main() {
  
  sf::RenderWindow window(sf::VideoMode(640, 480), "qtqst under construction");

  sf::View playerView(sf::Vector2f(0, 0), sf::Vector2f(640, 480));

  currentLevel = LevelPainter::paintEmptyLevel(64, 32);
  
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

    window.setView(playerView); //need to call setView everytime the view changes
    
    //currentLevel.updateRendition(dt);
    
    window.clear();
    window.draw(shape);
    window.display();
  }

  return 0;
}
