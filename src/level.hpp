#ifndef LEVEL_INCLUDE
#define LEVEL_INCLUDE

#include <vector>

#include "cell.hpp"
#include "entity.hpp"

class Level {

public:

  int width;
  int height;

  Level(int width, int height);    // initialize an empty level
  Level(std::vector<std::vector<Cell>>* cells); // initialize a level with a premade cell grid
  ~Level();
  void updateGameLogic(double dticks); // in ticks mind you!
  void updateRendition(double dt); // in seconds mind you!
  
private:

  std::vector<std::vector<Cell>>* cells;
  std::vector<Entity>* entities;   // everything that *lives* in the level goes here 
};

#endif // LEVEL_INCLUDE
