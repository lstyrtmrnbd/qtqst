#ifndef CELL_INCLUDE
#define CELL_INCLUDE

#include "terrain.hpp"
#include "inhabitant.hpp"

/**
 * -Holds a terrain, and a list of pointers to its current inhabitants
 */

class Cell {

public:

  Cell(Terrain terrain);

  Terrain::TerrainType getTerrainType();
  
  void push(Inhabitant* inhab);
  Inhabitant* pop();


private:

  Terrain terrain;
  std::vector<Inhabitant*> inhabitants;
};

#endif // CELL_INCLUDE
