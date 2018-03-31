#ifndef ENVIRONMENT_INCLUDE
#define ENVIRONMENT_INCLUDE

#include "terrain.hpp"
#include "SpriteBatch.hpp"

/**
 *Defines a mapping of terrain and buildings to sprites
 */
class Environment {

public:

  Environment(sf::Texture spritesheet);

  void setSpriteBox(TerrainType, sf::IntRect);
  sf::IntRect getSpriteBox(TerrainType);
  
private:

  sf::Texture* spritesheet;
  //std::vector<swift::Sprite> sprites; //this goes in the Level
  std::map<TerrainType, sf::IntRect>* terrainSpriteBoxes; 
  
};

#endife // ENVIRONMENT_INCLUDE
