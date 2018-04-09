#include <iostream>

#include <SFML/Graphics.hpp>

#include "existentenvironments.hpp"
#include "inputhandler.hpp"
#include "level.hpp"
#include "levelpainter.hpp"
#include "pather.hpp"

double secondsPerTick = 0.5;

const char* defaultTilesetFilename = "assets/technotiles.png";

sf::Texture* defaultSpritesheet;

ExistentEnvironments* environs;
LevelPainter* levelPainter;
Level* currentLevel;

InputHandler* handler; 


void testPathFinder(Region& region, std::pair<int, int> start, std::pair<int, int> end) {

  PathGraph* graph = Pather::parseRegion(region);
  Previousmap* prevMap = Pather::breadthFirst(*graph, end.first, end.second);
  Path* path = Pather::pathFromPrevious(*prevMap, start.first, start.second);

  std::cout << "----pathing----\n"
            << "graph " << *graph << "\n"
            << "prevMap size: " << prevMap->size() << "\n"
            << "path length: " << path->size() << "\n"
            << "---------------\n";

  Pather::doPath(*path, [&region](int x, int y) {

      Cell* cell = region.getRelativeCell(x, y);

      std::cout << "doPath visiting: " << x << ", " << y << "\n";
      
      if(cell != nullptr) cell->setTerrainType(Terrain::TerrainType::snow);
    });

  region.rebuildBatch();
}

int main() {
  
  sf::RenderWindow window(sf::VideoMode(640, 480), "qtqst under construction");

  int viewWidth = 2560/2;
  int viewHeight = 1920/2;
  
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

  Region regionZero = currentLevel->getRegion(0);

  testPathFinder(regionZero, std::make_pair(2, 2), std::make_pair(28, 28));
  
  std::cout << "Region 0 batch: " << regionZero.getBatch();
  
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

