#ifndef CELL_INCLUDE
#define CELL_INCLUDE

#include "terrain.hpp"
#include "inhabitant.hpp"

class Cell {

public:

  Cell(Terrain terrain);
  void push(Inhabitant* ent);
  Inhabitant* pop();

private:

  Terrain terrain;
  std::vector<Inhabitant*> inhabitants;
};

#endif // CELL_INCLUDE
