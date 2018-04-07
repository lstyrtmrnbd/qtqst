#ifndef TERRAIN_INCLUDE
#define TERRAIN_INCLUDE

#include <SFML/Graphics.hpp>

class Terrain {

public:

  enum TerrainType {
    grass,
    dirt,
    snow
  };

  Terrain(TerrainType);
  
  ~Terrain();

  TerrainType terrainType;
  int difficulty = 0; // additional difficulty applied to pathfinding cost

  friend std::ostream& operator<<(std::ostream&, const Terrain&);
};

#endif // TERRAIN_INCLUDE
