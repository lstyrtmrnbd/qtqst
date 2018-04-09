#include "terrain.hpp"

Terrain::Terrain(TerrainType terrainType): terrainType(terrainType), difficulty(0) {

}

Terrain::~Terrain() {

}

std::ostream& operator<<(std::ostream &out, const Terrain &terrain) {

  std::string outType;
    
  switch(terrain.terrainType) {

    case Terrain::grass:
      outType = std::string("grass");
      break;

    case Terrain::dirt:
      outType = std::string("dirt");
      break;

    case Terrain::snow:
      outType = std::string("snow");
      break;

    default:
      outType = std::string("!NO TERRAIN TYPE!");
      break;
  }
  
  return out << "Terrain of type " << outType << "\n"; 
}
