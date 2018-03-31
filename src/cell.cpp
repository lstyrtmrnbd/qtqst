#include "cell.hpp"

Cell::Cell(Terrain terrain): terrain(terrain) {

}

Terrain::TerrainType Cell::getTerrainType() {

  return terrain.terrainType;
}
