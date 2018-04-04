#include "cell.hpp"

Cell::Cell(Terrain terrain): terrain(terrain) {

}

Terrain::TerrainType Cell::getTerrainType() {

  return terrain.terrainType;
}

void Cell::setTerrainType(Terrain::TerrainType newTerrainType) {

  terrain.terrainType = newTerrainType;
}

std::ostream& operator<<(std::ostream &out, const Cell &cell) {

  return out << "Cell containing: \n" << cell.terrain;
}
