#ifndef CELL_INCLUDE
#define CELL_INCLUDE

#include "terrain.hpp"
#include "entity.hpp"

class Cell {

public:

  Cell(Terrain);
  void push(Entity);
  Entity pop();

private:

  Terrain terrain;
  std::vector<Entity> entities;
};

#endif // CELL_INCLUDE
