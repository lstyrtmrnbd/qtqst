#ifndef TERRAIN_INCLUDE
#define TERRAIN_INCLUDE

#include <SFML/Graphics.hpp>

class Terrain {

public:

  Terrain();

  enum Type {

    grass,
    dirt,
    snow

  };
  
private:

  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif // TERRAIN_INCLUDE
