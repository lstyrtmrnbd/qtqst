#ifndef ENVIRONMENT_INCLUDE
#define ENVIRONMENT_INCLUDE

#include "terrain.hpp"
#include "SpriteBatch.hpp"

/**
 * -Defines a mapping of terrain and buildings to sprites
 *
 * -Holds info to generate sprite batch and sprites
 * -DOES NOT hold anything necessary for rendering
 */
class Environment {

public:

  Environment(sf::Texture spritesheet);

  void setSpriteBox(TerrainType, sf::IntRect);
  sf::IntRect getSpriteBox(TerrainType);
  
private:

  sf::Texture* spritesheet;
  std::map<TerrainType, sf::IntRect>* terrainSpriteBoxes;
  
};

#endife // ENVIRONMENT_INCLUDE
