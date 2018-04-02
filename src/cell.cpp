#include "cell.hpp"

Cell::Cell(Terrain terrain): terrain(terrain) {

  std::cout << "Hi, I'm a new Cell. Please treat me well." << "\n";

}

Terrain::TerrainType Cell::getTerrainType() {

  return terrain.terrainType;
}

void Cell::announceSelf() {

  std::cout << "Hi i'm a cell." << "\n";
}
