#include <iostream>

#include <SFML/Graphics.hpp>

#include "inputhandler.hpp"
#include "existentenvironments.hpp"
#include "level.hpp"
#include "levelpainter.hpp"

double secondsPerTick = 0.5;

int main() {
  
  sf::RenderWindow window(sf::VideoMode(640, 480), "qtqst under construction");

  std::cout << "It got this far" << "\n";
  
  sf::View playerView(sf::Vector2f(0, 0), sf::Vector2f(640, 480));

  sf::Texture* defaultSpritesheet = new sf::Texture();
  if(!defaultSpritesheet->loadFromFile("assets/technotiles.png")) {

    std::cout << "It didn't load." << "\n";
  }

  std::cout << "The texture loaded" << "\n";
  
  ExistentEnvironments* environs = new ExistentEnvironments(defaultSpritesheet);

  std::cout << "Environments initialized" << "\n";

  LevelPainter* levelPainter = new LevelPainter(environs);

  std::cout << "LevelPainter initialized" << "\n";
  
  Level* currentLevel = levelPainter->paintEmptyLevel(64, 32);

  std::cout << "The currentLevel was painted" << "\n";
  
  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);

  sf::Clock clock;

  InputHandler handler(window, shape);

  std::cout << "Dropping into primary loop" << "\n";

  while (window.isOpen()) {
      
    sf::Event event;
        
    while (window.pollEvent(event)) {
          
      handler.handleInput(event);
    }

    sf::Time dt = clock.restart();

    window.setView(playerView); //need to call setView everytime the view changes
    
    currentLevel->render(dt.asSeconds(), window);
    
    window.clear();
    window.draw(shape);
    window.display();
  }

  return 0;
}
