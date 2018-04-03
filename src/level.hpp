#ifndef LEVEL_INCLUDE
#define LEVEL_INCLUDE

#include <vector>

#include "cell.hpp"
#include "entity.hpp"
#include "region.hpp"
#include "Sprite.hpp"

/**
 * -Holds the actual map cell grid and the entities of the map
 * -Maintains the Regions it contains, and delegates
 * -It is constructed by LevelPainter, which creates its major structures
 */

class Level {

public:

  // initialize a level with a premade cell grid and region assignments
  Level(std::vector<std::vector<Cell>>*, std::vector<Region>*);
  
  ~Level();
  
  void update(double dticks); // in ticks mind you!
  void render(double dtime, sf::RenderWindow& window);  // in seconds mind you!

  friend std::ostream& operator<<(std::ostream&, const Level&);
  
private:
  
  int width;
  int height;

  std::vector<std::vector<Cell>>* cells;
  std::vector<Entity>* entities;   // everything that *lives* in the level goes here 
  std::vector<Region>* regions;

  // animated sprites will be grabbed from each entity upon rendering
};

#endif // LEVEL_INCLUDE
