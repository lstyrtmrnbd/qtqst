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
 */

class Level {

public:

  int width;
  int height;

  // initialize a level with a premade cell grid and region assignments
  Level(std::vector<std::vector<Cell>>*, std::vector<Region>*);
  
  ~Level();
  
  void update(double dticks); // in ticks mind you!
  void render(double dtime); // in seconds mind you!
  
private:

  std::vector<std::vector<Cell>>* cells;
  std::vector<Entity>* entities;   // everything that *lives* in the level goes here 
  std::vector<Region>* regions;

  // std::vector<swift::Sprite>* staticSprites; // sprites for terrain & buildings
  // animated sprites will be grabbed from each entity upon rendering
};

#endif // LEVEL_INCLUDE
