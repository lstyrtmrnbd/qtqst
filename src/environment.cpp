#include "environment.hpp"

Environment::Environment(sf::Texture spritesheet): spritesheet(spritesheet) {

  terrainSpriteBoxes = new std::map<TerrainType, sf::IntRect>();
}

void Environment::setSpriteBox(TerrainType terrainType, sf::IntRect spriteBox) {

  (*terrainSpriteBoxes)[terrainType] = spriteBox;
}

sf::IntRect Environment::getSpriteBox(TerrainType terrainType) {

  return (*terrainSpriteBoxes)[terrainType];
}
