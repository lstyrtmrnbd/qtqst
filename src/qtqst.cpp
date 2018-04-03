#include <iostream>

#include <SFML/Graphics.hpp>

#include "inputhandler.hpp"
#include "existentenvironments.hpp"
#include "level.hpp"
#include "levelpainter.hpp"

double secondsPerTick = 0.5;

const char* defaultTileset = "assets/technotiles.png";

int main() {
  
  sf::RenderWindow window(sf::VideoMode(640, 480), "qtqst under construction");

  sf::View playerView(sf::Vector2f(0, 0), sf::Vector2f(1920, 1080));

  sf::Texture* defaultSpritesheet = new sf::Texture();
  
  if(!defaultSpritesheet->loadFromFile(defaultTileset)) {

    std::cout << defaultTileset << " failed to load" << "\n";
  } else {
    std::cout << defaultTileset << " loaded succesfully" << "\n";
  }

  ExistentEnvironments* environs = new ExistentEnvironments(defaultSpritesheet);

  std::cout << "Environments initialized" << "\n";

  LevelPainter* levelPainter = new LevelPainter(environs);

  std::cout << "LevelPainter initialized" << "\n";
  
  Level* currentLevel = levelPainter->paintEmptyLevel(64, 32);

  std::cout << "The currentLevel was painted, it's now:" << "\n";

  std::cout << *currentLevel;
  
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

    window.clear();
    
    currentLevel->render(dt.asSeconds(), window);
    window.draw(shape);
    
    window.display();
  }

  return 0;
}
