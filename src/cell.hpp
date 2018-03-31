#ifndef CELL_INCLUDE
#define CELL_INCLUDE

#include "terrain.hpp"
#include "inhabitant.hpp"

class Cell {

public:

  Cell(); //needs a default constructor for empty initialization of level
  Cell(Terrain terrain);
  void push(Inhabitant* inhab);
  Inhabitant* pop();

private:

  Terrain terrain;
  std::vector<Inhabitant*> inhabitants;
};

#endif // CELL_INCLUDE
