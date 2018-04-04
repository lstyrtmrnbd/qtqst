#ifndef CELL_INCLUDE
#define CELL_INCLUDE

#include <iostream>

#include "terrain.hpp"
#include "inhabitant.hpp"

/**
 * -Holds a terrain, and a list of pointers to its current inhabitants
 */
class Cell {

public:

  Cell(Terrain terrain);

  Terrain::TerrainType getTerrainType();
  void setTerrainType(Terrain::TerrainType);
  
  void push(Inhabitant* inhab);
  Inhabitant* pop();

  friend std::ostream& operator<<(std::ostream&, const Cell&);

private:

  Terrain terrain;
  std::vector<Inhabitant*> inhabitants;
};

#endif // CELL_INCLUDE
