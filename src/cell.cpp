#include "cell.hpp"

Cell::Cell(Terrain terrain): terrain(terrain) {

}

Terrain::TerrainType Cell::getTerrainType() {

  return terrain.terrainType;
}

std::ostream& operator<<(std::ostream &out, const Cell &cell) {

  return out << "Cell containing: \n" << cell.terrain;
}
