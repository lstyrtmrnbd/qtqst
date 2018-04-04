#include <iostream>

#include <SFML/Graphics.hpp>

#include "inputhandler.hpp"
#include "existentenvironments.hpp"
#include "level.hpp"
#include "levelpainter.hpp"

double secondsPerTick = 0.5;

const char* defaultTilesetFilename = "assets/technotiles.png";

sf::Texture* defaultSpritesheet;

ExistentEnvironments* environs;
LevelPainter* levelPainter;
Level* currentLevel;

InputHandler* handler; 

int main() {
  
  sf::RenderWindow window(sf::VideoMode(640, 480), "qtqst under construction");

  int viewWidth = 2560/4;
  int viewHeight = 1920/4;
  
  sf::View playerView(sf::Vector2f(viewWidth/2, viewHeight/2),
                      sf::Vector2f(viewWidth, viewHeight));

  defaultSpritesheet = new sf::Texture();
  
  if(!defaultSpritesheet->loadFromFile(defaultTilesetFilename)) {
    std::cout << defaultTilesetFilename << " failed to load" << "\n";
  } else std::cout << defaultTilesetFilename << " loaded succesfully" << "\n";

  environs = new ExistentEnvironments(defaultSpritesheet);
  levelPainter = new LevelPainter(environs);

  std::cout << "Singletons started" << "\n";
  
  currentLevel = levelPainter->paintEmptyLevel(64, 32);

  std::cout << "Current level painted: "<< *currentLevel;

  std::cout << "Region 0 batch: " << currentLevel->getRegion(0).getBatch();

  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);

  sf::Clock clock;

  handler = new InputHandler(window, shape); // although this is singleton too

  std::cout << "Dropping into primary loop" << "\n";
  while (window.isOpen()) {
      
    sf::Event event;
        
    while (window.pollEvent(event)) {
          
      handler->handleInput(event);
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
