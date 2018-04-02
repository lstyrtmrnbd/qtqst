#ifndef TERRAIN_INCLUDE
#define TERRAIN_INCLUDE

#include <SFML/Graphics.hpp>

class Terrain {

public:

  // how broad should this be?
  enum TerrainType {

    grass,
    dirt,
    snow

  };

  Terrain(TerrainType);
  
  ~Terrain();

  TerrainType terrainType;

  friend std::ostream& operator<<(std::ostream&, const Terrain&);
  
private:

};

#endif // TERRAIN_INCLUDE
